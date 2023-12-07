# %%
import serial
# import time

com2 = serial.Serial()

# %%
# declarando as portas seriais
com2.port = "COM2"

com2.baudrate = 9600


com2.timeout = 1


com2.open()

while(True):
    com2.write('C'.encode())

    print(com2.readline())  # leitura da porta serial

    # se a tecla 'q' for pressionada, o loop é interrompido
    # if input() == 'q':
    #     break
# %%
com2.close()



# %%
