#define F_CPU 8000000UL
#include <avr/io.h>
#include "uart.c"
#include "adc.c"

volatile uint8_t current_channel = ADC0;

int main(void)
{
    uartBegin(9600, F_CPU); //Inicializa UART
    adcBegin(AVCC, 0x01); //Inicializa ADC
    adcChannel(current_channel); //Seleciona canal
    adcIntEn(1); //Interrupção do A/D
    uartIntRx(1); //Interrupção da uart
    sei(); //Interrupção geral
    while (1); //Laço infinito
}

//Tratamendo da interrupção de recepção de dados
ISR(USART_RX_vect)
{
    if (uartRx() == 'C')//Verifica se recebeu 'C'
        adcSample(); //Inicia conversão
}

//Tratamendo da interrupção do A/D
ISR(ADC_vect)
{
    // Verifica qual canal está sendo lido e envia o nome correspondente para a UART
    if (current_channel == ADC0) {
        uartString("Canal: ADC0, Valor: ");
    } else {
        uartString("Canal: ADC1, Valor: ");
    }

    uartDec2B(adcReadOnly());//Ler e envia valor do A/D
    uartString("\r\n");

    // Alterna entre os canais ADC0 e ADC1
    if (current_channel == ADC0) {
        current_channel = ADC1;
    } else {
        current_channel = ADC0;
    }
    // adcChannel(current_channel); //Seleciona novo canal
}