/*
 * ADC_Home.c
 *
 * Created: 10/14/2021 7:04:22 PM
 * Author : Dell
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
#include "Std_Types.h"
#include <util/delay.h>

int main(void)
{
	ADC_Init(&ADC_Config);
	LCD_Init();
	uint16 ADCReading = 0U;
	while (1)
	{
		ADCReading = ADC_Read(ADC_Channel1);
		LCD_IntegerDisplay(ADCReading);
		_delay_ms(500);
		LCD_Clear();

	}
}

