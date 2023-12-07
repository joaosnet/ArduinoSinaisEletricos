#define F_CPU 8000000UL
#include <avr/io.h>
#include "adc.h"
#include "uart.h"
int main(void)
{ uartBegin(9600, F_CPU); //Inicializa UART
	adcBegin(AVCC, 0x01); //Inicializa A/D
	adcChannel(ADC0); //Seleciona canal
	adcIntEn(1); //Interrup��o do A/D
	sei(); //Interrup��o geral
	while (1)
	{ if (uartRxOk()) //verifica se existe novo dado na uart
		if (uartRx() == 'C')//Se sim, verifica se foi 'C'
		adcSample(); //Inicia convers�o
	}
}
//Tratamendo da interrup��o do A/D
ISR(ADC_vect)
{ uartString("Valor: "); //Envia string
	uartDec2B(adcReadOnly());//Ler e envia valor do A/D
	uartString("\r\n"); //Nova linha
}