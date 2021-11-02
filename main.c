/*
 * SPI.c
 *
 * Created: 10/30/2021 3:29:17 PM
 * Author : Dell
 */ 

#include <avr/io.h>
#include "SPI.h"
#include "LCD.h"
#include <util/delay.h>

int main(void)
{
   SPI_Init(&gStrSpi_Configuration);
   LCD_Init();
   uint8 u8LocalData = 0U;
    while (1) 
    {
		
		LCD_RowCol_Select(0,5);
		LCD_StringDisplay("Master Node");
		LCD_RowCol_Select(1,5);
		LCD_IntegerDisplay(u8LocalData);
		SPI_MasterTx(u8LocalData);
		
		_delay_ms(1000);
		u8LocalData = (u8LocalData+1)%10;
		LCD_Clear();
		
    }
}

