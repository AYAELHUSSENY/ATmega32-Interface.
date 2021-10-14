/*
 * Switch.c
 *
 * Created: 9/29/2021 9:11:56 PM
 *  Author: Dell
 */ 
 #include "ATmega32_Configuration.h"
 #include "DIO.h"
 #include "Led.h"
 #include "Std_Types.h"
 #include "Macros.h"
 #include "Switch.h"
#include <util/delay.h>
#define DEBOUNCE_PERIOD (20U)

 void Switch_Init(volatile uint8 * Port_reg , SwitchPinEnum_t channel){
 DioChannelDirectionSet(Port_reg,channel,DIO_INPUT);


 }
 //----------------------------------------------------------------------------------------
 DioPinStateEnum_t SwitchPrevState = SWITCH_OFF;
 SwitchStateEnum_t SwitchStateGet(volatile uint8 * Port_reg , SwitchPinEnum_t channel){
			SwitchStateEnum_t LocalSwitchState = SWITCH_OFF;
			if(SwitchPrevState != DioChannelRead(Port_reg,channel))
			{
				_delay_ms(DEBOUNCE_PERIOD);
				SwitchPrevState = DioChannelRead(Port_reg,channel);
				if(SwitchPrevState == DIO_HIGH){
				LocalSwitchState = SWITCH_ON;
				}
				else
				{
				LocalSwitchState = SWITCH_OFF;

				}

			}
			return LocalSwitchState;
 }
