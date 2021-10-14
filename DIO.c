/*
 * DIO.c
 *
 * Created: 9/29/2021 5:46:04 PM
 *  Author: Dell
 */ 
#include "DIO.h"
#include "Led.h"
#include "Std_Types.h"
#include "Macros.h"
#include "ATmega32_Configuration.h"
 // functions implementation of Digital Input and Outputs 
 void DioChannelDirectionSet(volatile uint8 * Port_reg , Dio_PinEnum_t channel,DioPinDirectioinEnum_t Direction){
		switch(Direction){
		case DIO_INPUT:
		CLEAR_BIT(*Port_reg,channel);
		break;
		case DIO_OUTPUT:
		SET_BIT(*Port_reg,channel);
		break;
		default:
		break;
		 }
		 }


//------------------------------------------------------------------------------------------------------
void DioChannelWrite(volatile uint8 * Port_reg, Dio_PinEnum_t channel , DioPinStateEnum_t State){
		 switch(State){
			 case DIO_LOW:
			 CLEAR_BIT(*Port_reg,channel);
			 break;
			 case DIO_HIGH:
			 SET_BIT(*Port_reg,channel);
			 break;
			 default:
			 break;
		 }						
		 }
//-------------------------------------------------------------------------------------------------------
DioPinStateEnum_t DioChannelRead( volatile uint8 * Port_reg ,Dio_PinEnum_t channel){
DioPinStateEnum_t u8LocalPinValue = READ_BIT(*Port_reg , channel);
return u8LocalPinValue;
}
//-------------------------------------------------------------------------------------------------------
void DioChannelToggle( volatile uint8 * Port_reg , Dio_PinEnum_t channel){
TOGGLE_BIT(*Port_reg,channel);
}
//-------------------------------------------------------------------------------------------------------
void DioPortWrite( volatile uint8 * Port_reg , uint8 Value ){
*Port_reg = Value;
}
//-------------------------------------------------------------------------------------------------------
uint8 DioPortRead(volatile uint8 * port_reg){
uint8 u8LocalPortValue = *port_reg;
return u8LocalPortValue;
}














