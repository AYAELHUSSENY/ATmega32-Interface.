/*
 * Uart.c
 *
 * Created: 10/23/2021 3:57:48 PM
 * Author : Dell
 */ 

#include <avr/io.h>
#include "Uart.h"
#include <util/delay.h>

int main(void)
{
	Uart_Init();
	
    while (1) 
    {	
			Uart_StringTransmit("Aya_Elhusseny :)");
			_delay_ms(1000);

	}


}

