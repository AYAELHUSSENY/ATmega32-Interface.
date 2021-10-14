/*
 * Led.c
 *
 * Created: 9/29/2021 7:09:05 PM
 *  Author: Dell
 */ 
 
 #include "DIO.h"
 #include "Led.h"
 #include "Std_Types.h"
 #include "Macros.h"
 #include "ATmega32_Configuration.h"
 
 // functions implementation
 void Led_Init( volatile uint8 * Led_reg , LedPinEnum_t LedNumber){
 DioChannelDirectionSet(Led_reg,LedNumber,DIO_OUTPUT);
 }
 //----------------------------------------------------------------
 void Led_StateSet(volatile uint8 * Led_reg , LedPinEnum_t LedNumber , LedStateEnum_t State){
		if(State == LED_TOGGLE){
		DioChannelToggle(Led_reg,LedNumber);
		}
		else{
		DioChannelWrite(Led_reg,LedNumber,State);
		}
 }
 //------------------------------------------------------------------

