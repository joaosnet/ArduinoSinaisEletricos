# %%
import serial
import time
import pandas as pd

com2 = serial.Serial()

# %%
# declarando as portas seriais
com2.port = "COM2"

com2.baudrate = 9600

com2.timeout = 1

# Configuração da taxa de amostragem
taxa_amostragem = 1000  # 1 kHz

# Tempo de espera para a estabilização do Arduino
time.sleep(2)


df = pd.DataFrame()

com2.open()

# inicializando um contador
contador = 0
while True:
    com2.write('C'.encode())
    # formantando a string de leitura Canal: ADC0, Valor: 443
    string = com2.readline().decode('utf-8')
    lista = string.split(', ')
    # print(string)
    # print(lista)

    if len(lista) > 1 and ': ' in lista[1]:
        # print(lista[1].split(': ')[1])
        tensao = float(lista[1].split(': ')[1])  # Convertendo a string para float Canal: ADC0, Valor: 443
        # convertendo a tensao de 0-1023 para 0-5V
        tensao = tensao * 5 / 1023
        pino = lista[0].split(': ')[1]
        if pino == 'ADC0':
            corrente = tensao / 180
        else:
            corrente = tensao / 1000
        # Formatando o tempo para milisegundos
        tempo = time.time() * 1000
            
        if corrente is not None and tensao is not None:
            print("Leitura de sinais da porta {}".format(pino))
            print(f"Corrente: {corrente} A")
            print(f"Tensão: {tensao} V") 

        df = df._append({"Tempo": tempo, f"{pino}_tensao": tensao,  f"{pino}_corrente": corrente}, ignore_index=True)
        contador += 1
        if contador == 100:
            break
    else:
        print("String não formatada corretamente")

    # Para o loop por 1 / taxa_amostragem segundos
    time.sleep(1 / taxa_amostragem)

# Encerra o loop quando o usuário pressiona Ctrl+C
com2.close()
df.to_csv("amostras.csv")
print(df)

import matplotlib.pyplot as plt

plt.figure(figsize=(30, 8))

# Plotando ADC0_tensao
plt.subplot(2, 2, 1)  # subplot com 2 linhas e 2 colunas, este é o primeiro gráfico
plt.stem(df['Tempo'], df['ADC0_tensao'], 'g')
plt.title('Tensão no Resistor 180 Ohms')
plt.xlabel('Tempo(milisegundos)')
plt.ylabel('Valor(volts)')
plt.grid(True)

# Plotando ADC0_corrente
plt.subplot(2, 2, 2)  # subplot com 2 linhas e 2 colunas, este é o segundo gráfico
plt.stem(df['Tempo'], df['ADC0_corrente'], 'b')
plt.title('Corrente no Resistor 180 Ohms')
plt.xlabel('Tempo(milisegundos)')
plt.ylabel('Valor(Amperes)')
plt.grid(True)

# Plotando ADC1_tensao
plt.subplot(2, 2, 3)  # subplot com 2 linhas e 2 colunas, este é o terceiro gráfico
plt.stem(df['Tempo'], df['ADC1_tensao'], 'r')
plt.title('Tensão na Carga')
plt.xlabel('Tempo(milisegundos)')
plt.ylabel('Valor(volts)')
plt.grid(True)

# Plotando ADC1_corrente
plt.subplot(2, 2, 4)  # subplot com 2 linhas e 2 colunas, este é o quarto gráfico
plt.stem(df['Tempo'], df['ADC1_corrente'], 'm')
plt.title('Corrente na Carga')
plt.xlabel('Tempo(milisegundos)')
plt.ylabel('Valor(Amperes)')
plt.grid(True)

plt.tight_layout()  # garante um bom espaçamento entre os gráficos
plt.show()
