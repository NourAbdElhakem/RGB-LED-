#define F_CPU 8000000
#define KEYPAD_PROG
#include <stdlib.h>
#include <util/delay.h>
#include "STDTYPS.h"
#include "MEMMAP.h"
#include "UTILS.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC.h"
#include "timer.h"
#include "RGP_LED.h"





int main(void)
{
	
sei();
	
	DIO_INITPIN();
	LCD_INIT();
	ADC_Init(VREF_VCC,ADC_SCALER_64);
	LCD_Clear();
	
LCD_writeString("RX");

UART_init();

u16 x ;
RGB_INIT();

RGB_SETCOLOR(GREEN);

	while(1) 
	{



	}
	
	
	
}



void UART_SendStringCheckSum(u8*str){	u8 len=0;	u16 sum=0;	for (len=0;str[len];len++)	{			}	UART_Send(len);	for (len=0;str[len];len++)	{		UART_Send(str[len]);		sum+=str[len];	}	UART_Send((u8)sum);	UART_Send((u8)(sum>>8));		}


u8 UART_RecievestringChecksum(u8*str)
{
	
	u8 len,sum_calc=0 ,i=0;
	
	u16 b0,b1,sum_s;
	
	len=UART_Receive();
	
	for(i=0;i<len;++i)
	{
		
		str[i]=UART_Receive();
		
	sum_calc=sum_calc+str[i];
		
	}
	
	b0=UART_Receive();
	b1=UART_Receive();
	
	sum_s=(u16)b0|(u16)(b1<<8);
	
	
	if(sum_s==sum_calc)
	{
		
		return 1 ;
	}
	else
	{
		return 0 ;
	}
	
	
		
	
}