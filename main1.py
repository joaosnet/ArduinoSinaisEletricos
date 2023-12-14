import sys

import pyqtgraph as pg
from pyqtgraph.Qt import QtCore, QtWidgets

import numpy as np

from pyfirmata2 import Arduino

import pandas as pd

import time

PORT = 'COM7'
# taxa de amostragem: 1kHz
taxaAmostragem = 1000

class QtPanningPlot:

    def __init__(self, titulo):
        self.pw = pg.PlotWidget()
        self.pw.setYRange(-1, 1)
        self.pw.setXRange(0, 500/taxaAmostragem)
        self.plt = self.pw.plot()
        self.data = []
        # qualquer código de inicialização adicional vai aqui (filtros etc)
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.update)
        self.timer.start(100)

    def getWidget(self):
        return self.pw
        
    def update(self):
        self.data = self.data[-500:]
        if self.data:
            self.plt.setData(x=np.linspace(0, len(self.data)/taxaAmostragem, len(self.data)), y=self.data)

    def addData(self, d):
        self.data.append(d)

app = pg.mkQApp()
mw = QtWidgets.QMainWindow()
mw.setWindowTitle('1kHz duplo PlotWidget')
mw.resize(800, 800)
cw = QtWidgets.QWidget()
mw.setCentralWidget(cw)

# Vamos organizar os dois gráficos horizontalmente
layout = QtWidgets.QHBoxLayout()
cw.setLayout(layout)

# Vamos criar duas instâncias de janelas de gráfico
qtPanningPlot1 = QtPanningPlot("1º canal do Arduino")
layout.addWidget(qtPanningPlot1.getWidget())

qtPanningPlot2 = QtPanningPlot("2º canal do Arduino")
layout.addWidget(qtPanningPlot2.getWidget())

# Crie um DataFrame para armazenar os dados
df = pd.DataFrame(columns=['Tempo', 'Canal 0', 'Canal 1'])

ref = 1.1

class filter_of_channel0():

    def dofilter(data):
        data = (data * ref)/1024
        return data
    
class filter_of_channel1():
    
    def dofilter(data):
        data = (data * ref)/1024
        return data

# chamado para cada nova amostra no canal 0 que chegou do Arduino
# "data" contém a nova amostra
def callBack1(data):
    # filtre suas amostras do canal 0 aqui:
    # data = filter_of_channel0.dofilter(data)
    # envie a amostra para a janela de plotagem
    qtPanningPlot1.addData(data)
    # Adicione os dados ao DataFrame
    df.loc[len(df)] = [time.time(), data, None]

# chamado para cada nova amostra no canal 1 que chegou do Arduino
# "data" contém a nova amostra
def callBack2(data):
    # filtre suas amostras do canal 1 aqui:
    # data = filter_of_channel1.dofilter(data)
    # envie a amostra para a janela de plotagem
    qtPanningPlot2.addData(data)
    # Adicione os dados ao DataFrame
    if len(df) > 0:
        df.loc[len(df) - 1, 'Canal 1'] = data

# Obtenha a placa Arduino.
board = Arduino(PORT)

# Defina a taxa de amostragem no Arduino
board.samplingOn(1000 / taxaAmostragem)

# Registre o retorno de chamada que adiciona os dados ao gráfico animado
board.analog[0].register_callback(callBack1)
board.analog[5].register_callback(callBack2)

# Ative o retorno de chamada
board.analog[0].enable_reporting()
board.analog[5].enable_reporting()

# mostrando os gráficos
mw.show()

# Iniciando a GUI do QT
# Esta é uma chamada bloqueante e só retorna quando o usuário fecha a janela.
pg.exec()

# No final do script, salve o DataFrame em um arquivo CSV
df.to_csv('dados.csv', index=False)

# precisa ser chamado para fechar a porta serial
board.exit()

print("Finalizado")
