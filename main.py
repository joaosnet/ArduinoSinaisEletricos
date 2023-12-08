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


col = ["Tempo","ADC0", "ADC1"]
df = pd.DataFrame(columns=col)

com2.open()

# Loop principal
try:
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
            pino = lista[0].split(': ')[1]
            if pino == 'ADC0':
                corrente = tensao / 180
            else:
                corrente = tensao / 1000

            if corrente is not None and tensao is not None:
                print("Leitura de sinais da porta {}".format(lista[0].split(': ')[1]))
                print(f"Corrente: {corrente} A")
                print(f"Tensão: {tensao} V") 

                df = df._append({"Tempo": time.time(), "ADC0": tensao, "ADC1": corrente}, ignore_index=True)
        else:
            print("String não formatada corretamente")
            # Para o loop por 1 / taxa_amostragem segundos
        time.sleep(1 / taxa_amostragem)
except KeyboardInterrupt:
    # Encerra o loop quando o usuário pressiona Ctrl+C
    com2.close()
    df.to_excel("amostras.xlsx")
    print(df)
    # monstrando em um gráfico do pyplot no tempo discreto
    df.plot(x='Tempo', y=['ADC0', 'ADC1'])
    plt.show()


