/*
 * Timers.c
 *
 * Created: 10/15/2021 1:52:55 PM
 * Author : Dell
 */ 
 #include <avr/interrupt.h>
#include "GPT.h"
#include "External_Interrupts.h"
#include "Led.h"
uint16 gu16TimerCounter; // it will be initialized already by 0 in the bss section by the start up code 

ISR(TIMER0_COMP_vect)
{
	gu16TimerCounter++;
}
int main(void)
{		
		Gpt_Init(GPT0,GPT_MODE_CTC,GPT_PRESCALE_256,GPT_INTERRUPT_ENABLE,11U);
		Global_Interrupt_State_SET(GLOBALE_INTERRUPT_ENABLE);
		Led_Init(LED0_1_DIR_REG,LED0);
/* 
			F_cpu = 16*10^6
			prescale = 8
			F_timer = 2*10^6
			Tick_Time = 1/F_timer
			Tick_Time = 1/2*10^6 = 0.5 micro second
			overflow_time = 0.5 micro second * 255 = 1.275 * 10^-4 sec = 0.1275 sec
			1 ms --> 10 Overflow
																								*/
			while (1)
			{
				if(gu16TimerCounter == 5000)
				{
				Led_StateSet(LED0_1_OUT_REG,LED0,LED_TOGGLE);
				gu16TimerCounter = 0U;

				}
			}
}

