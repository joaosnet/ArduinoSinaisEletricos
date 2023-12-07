try:
    from pyfirmata import Arduino, util
except ModuleNotFoundError:
    import pip
    # pip install pyfirmata
    pip.main(['install', 'pyfirmata'])

import time

# Configuração da placa Arduino
board = Arduino('COM1')  # Substitua 'COMX' pela porta do seu Arduino

# Configuração dos pinos para corrente e tensão
pino_corrente = board.get_pin('a:0:i')  # Pino analógico A0 para corrente
pino_tensao = board.get_pin('a:1:i')    # Pino analógico A1 para tensão

# Configuração da taxa de amostragem
taxa_amostragem = 1000  # 1 kHz

# Tempo de espera para a estabilização do Arduino
time.sleep(2)

# Função para ler e imprimir os valores de corrente e tensão
def ler_sinais():
    corrente = pino_corrente.read()
    tensao = pino_tensao.read()

    if corrente is not None and tensao is not None:
        print(f"Corrente: {corrente * 5} A")  # Supondo um sensor de corrente com escala 0-5V
        print(f"Tensão: {tensao * 5} V")  # Supondo um sensor de tensão com escala 0-5V

# Loop principal
try:
    while True:
        ler_sinais()
        time.sleep(1 / taxa_amostragem)

except KeyboardInterrupt:
    # Encerra o loop quando o usuário pressiona Ctrl+C
    board.exit()
