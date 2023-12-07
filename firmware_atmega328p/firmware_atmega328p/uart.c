/*
 * uart.c
 * Implementacoes das funcoes da biblioteca uart.
 * Para o microcontrolador ATmega328P
 * Foi testada velocidade ate 38400 bps com clock de 8 MHz
 * Created: 29/08/2020 17:00:00
 * Author: Adalbery
 */ 

#include "uart.h"

//---------------------------------------------------------------------------
//inicializa a porta de comunica��o uart do ATmega328
//---------------------------------------------------------------------------
void uartBegin(uint32_t baud, uint32_t freq_cpu)
{ uint16_t myubrr = freq_cpu/16/baud-1;//calcula valor do registrador UBRR
  UBRR0H = (uint8_t)(myubrr>>8);	//ajusta a taxa de transmiss�o
  UBRR0L = (uint8_t)myubrr;
  UCSR0A = 0;//desabilitar velocidade dupla (no Arduino � habilitado por padr�o)
  UCSR0B = (1<<RXEN0)|(1<<TXEN0);//Habilita a transmiss�o e recep��o. Sem interrupcao |(1<<RXCIE0)|(1<<TXCIE0)
  UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);//modo ass�ncrono, 8 bits de dados, 1 bit de parada, sem paridade 
}

//---------------------------------------------------------------------------
//verifica se novo dado pode ser enviado pela UART
//---------------------------------------------------------------------------
uint8_t uartTxOk (void)
{ return (UCSR0A & (1<<UDRE0));//retorna valor 32 se novo dado pode ser enviado. Zero se n�o.
}

//---------------------------------------------------------------------------
//Envia um byte pela porta uart
//---------------------------------------------------------------------------
void uartTx(uint8_t dado)
{ UDR0 = dado;//envia dado 
}

//---------------------------------------------------------------------------
//verifica se UART possui novo dado
//retorna valor 128 se existir novo dado recebido. Zero se n�o.
//---------------------------------------------------------------------------
uint8_t uartRxOk (void)
{ return (UCSR0A & (1<<RXC0));
}

//---------------------------------------------------------------------------
//Ler byte recebido na porta uart
//---------------------------------------------------------------------------
uint8_t uartRx()
{ return UDR0; //retorna o dado recebido
}

//---------------------------------------------------------------------------
//Habilita ou desabilita interrup��o de recep��o da usart
//x = 0, desabilita interrup��o. x = 1, habilita interrup��o
//---------------------------------------------------------------------------
void uartIntRx(uint8_t x)
{ if (x)
    UCSR0B |= (1<<RXCIE0);//Habilita interrup��o de recep��o de dados
  else
    UCSR0B &= ~(1<<RXCIE0);//Desabilita interrup��o de recep��o de dados
}

//---------------------------------------------------------------------------
//Habilita ou desabilita interrup��o de Trasnmiss�o da usart
//x = 0, desabilita interrup��o. x = 1, habilita interrup��o
//---------------------------------------------------------------------------
void uartIntTx(uint8_t x)
{ if (x)
    UCSR0B |= (1<<TXCIE0);//Habilita interrup��o de recep��o de dados
  else
    UCSR0B &= ~(1<<TXCIE0);//Desabilita interrup��o de recep��o de dados
}

//---------------------------------------------------------------------------
//Envia uma string pela porta uart. Ultimo valor da string deve ser 0.
//---------------------------------------------------------------------------
void uartString(char *c)
{ for (; *c!=0; c++)
  { while (!uartTxOk());	//aguarda �ltimo dado ser enviado
    uartTx(*c);
  }    
}

//---------------------------------------------------------------------------
//Envia pela uart variavel de 1 byte (8 bits) com digitos em decimal
//---------------------------------------------------------------------------
void uartDec1B(uint8_t valor)
{ int8_t disp;
  char digitos[3];
  int8_t conta = 0;
  do //converte o valor armazenando os algarismos no vetor digitos
  { disp = (valor%10) + 48;//armazena o resto da divisao por 10 e soma com 48
    valor /= 10;
    digitos[conta]=disp;
    conta++;
  } while (valor!=0);
  for (disp=conta-1; disp>=0; disp-- )//envia valores do vetor digitos
  { while (!uartTxOk());  //aguarda �ltimo dado ser enviado
    uartTx(digitos[disp]);//envia algarismo
  }
}

//---------------------------------------------------------------------------
//Envia pela uart variavel de 2 bytes (16 bits) com digitos em decimal
//---------------------------------------------------------------------------
void uartDec2B(uint16_t valor)
{ int8_t disp;
  char digitos[5];
  int8_t conta = 0;
  do //converte o valor armazenando os algarismos no vetor digitos
  { disp = (valor%10) + 48;//armazena o resto da divisao por 10 e soma com 48
    valor /= 10;
    digitos[conta]=disp;
    conta++;
  } while (valor!=0);
  for (disp=conta-1; disp>=0; disp-- )//envia valores do vetor digitos
  { while (!uartTxOk());	 //aguarda �ltimo dado ser enviado
    uartTx(digitos[disp]);//envia algarismo    
  }
}  

//---------------------------------------------------------------------------
//Envia pela uart variavel de 4 bytes (32 bits) com digitos em decimal
//---------------------------------------------------------------------------
void uartDec4B(uint32_t valor)
{ int8_t disp;
  char digitos[10];
  int8_t conta = 0;
  do //converte o valor armazenando os algarismos no vetor digitos
  { disp = (valor%10) + 48;//armazena o resto da divisao por 10 e soma com 48
    valor /= 10;
    digitos[conta]=disp;
    conta++;
  } while (valor!=0);
  for (disp=conta-1; disp>=0; disp-- )//envia valores do vetor digitos
  { while (!uartTxOk());	 //aguarda �ltimo dado ser enviado
    uartTx(digitos[disp]);//envia algarismo    
  }
}

//---------------------------------------------------------------------------
//Envia pela uart variavel de 1 byte (8 bits) com digitos em hexadecimal
//---------------------------------------------------------------------------
void uartHex1B(uint8_t valor)
{ uint8_t disp;
  disp = (valor%16) + 48;    //armazena o resto da divisao por 16 e soma com 48
  if (disp > 57) disp += 7;  //soma 7 se algarismo for uma letra devido tabela ascii
  valor = (valor / 16) + 48; //armazena o resto da divisao por 16 e soma com 48
  if (valor > 57) valor += 7;//soma 7 se algarismo for uma letra devido tabela ascii
  while (!uartTxOk());	     //aguarda �ltimo dado ser enviado
  uartTx(valor);             //envia digito mais significativo
  while (!uartTxOk());	     //aguarda �ltimo dado ser enviado
  uartTx(disp);             //envia digito menos significativo
}

//---------------------------------------------------------------------------
//Envia pela uart variavel de 2 bytes (16 bits) com digitos em hexadecimal
//---------------------------------------------------------------------------
void uartHex2B(uint16_t valor)
{ uint8_t disp0;
  uint8_t disp1;
  disp0 = (uint8_t) (valor & 0x00FF);//armazena byte menos significativo
  disp1 = (uint8_t) (valor >> 8);    //armazena byte mais significativo
  uartHex1B(disp1);               //envia byte mais significativo
  uartHex1B(disp0);               //envia byte menos significativo
}

//---------------------------------------------------------------------------
//Envia pela uart variavel de 4 bytes (32 bits) com digitos em hexadecimal
//---------------------------------------------------------------------------
void uartHex4B(uint32_t valor)
{ uint16_t disp0;
  uint16_t disp1;
  disp0 = (uint16_t) (valor & 0x0000FFFF);//armazena dois bytes menos significativos
  disp1 = (uint16_t) (valor >> 16);       //armazena dois bytes mais significativos
  uartHex2B(disp1);                    //envia dois bytes mais significativos
  uartHex2B(disp0);                    //envia dois bytes menos significativos
}