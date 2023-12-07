/*
 * usart_teste_biblioteca.c
 * Programa para testar as funcoes da biblioteca uart.
 * Foi testada velocidade ate 38400 bps com clock de 8 MHz
 * Created: 29/08/2020 17:00:00
 * Author : Adalbery
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "uart.h"

int main(void)
{ char texto[] = "Envio de string.\r\n";
  uartBegin(9600, F_CPU);
  while (1) 
  { uartString(texto);    //mostra uma string
    
    while (!uartTxOk());	//aguarda o ultimo dado ser enviado
    uartTx(65);           //envia o caracter 'A' pela porta uart
    uartString("\r\n");   //Nova linha

    uartDec1B(123);       //mostra um valor em decimal. 1 Byte
    uartString("\r\n");   //Nova linha
    
    uartDec2B(12345);     //mostra um valor em decimal. 2 Bytes
    uartString("\r\n");   //Nova linha

    uartDec4B(1234567890);//mostra um valor em decimal. 4 Bytes
    uartString("\r\n");   //Nova linha
    
    uartHex1B(0x1A);      //mostra um valor em hexadecimal. 1 Byte
    uartString("\r\n");   //Nova linha
 
    uartHex2B(0x1A2B);    //mostra um valor em hexadecimal. 2 Bytes
    uartString("\r\n");   //Nova linha

    uartHex4B(0x1A2B3C4D);//mostra um valor em hexadecimal. 4 Bytes
    uartString("\r\n");   //Nova linha
    
    if (uartRxOk()) //verifica se houve dado recebido pela porta uart
    { uartString("Foi recebido: "); //mostra uma string
      while (!uartTxOk());  //aguarda o ultimo dado ser enviado
      uartTx(uartRx());     //retorna pela uart o valor recebido
      uartString("\r\n");   //Nova linha
    }       
    uartString("\r\n");   //Nova linha    
    _delay_ms(2000);      //delay
  }
}