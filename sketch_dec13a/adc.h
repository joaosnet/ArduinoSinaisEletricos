/*
 * adc.h
 * Definicoes das funcoes da biblioteca do
 * conversor anal�gico/digital.
 * Para o microcontrolador ATmega328P.
 * Created: 08/09/2020
 * Author: Caio e Adalbery
 */ 

#ifndef ADC_H_
#define ADC_H_
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define AREF 0 //Tens�o de refer�ncia = Aref
#define AVCC 1 //Tens�o de refer�ncia = Avcc
#define VR11 2 //Tens�o de refer�ncia = 1,1 V
#define ADC0 0 //Seleciona ADC0
#define ADC1 1 //Seleciona ADC1
#define ADC2 2 //Seleciona ADC2
#define ADC3 3 //Seleciona ADC3
#define ADC4 4 //Seleciona ADC4
#define ADC5 5 //Seleciona ADC5
#define Vtemp 6 //Seleciona Sensor de temperatura
#define V11   7 //seleciona tens�o de 1,1 V
#define Vgnd  8 //seleciona GND

void adcBegin(uint8_t ref, uint8_t did);//Inicializa o ADC
void adcChannel(uint8_t channel);       //Seleciona canal
void adcIntEn(uint8_t x);               //Habilita interrup��o
void adcSample(void);                   //Inicia convers�o
uint8_t  adcOk(void);                   //Verifica se convers�o foi conclu�da
uint16_t adcReadOnly();                 //Ler ADC
uint16_t adcRead();                     //Converte, aguarda e ler ADC

#endif /* ADC_H_ */