/*
 * Switch.h
 *
 * Created: 9/29/2021 9:00:04 PM
 *  Author: Dell
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_
#include "DIO.h"
#include "Std_Types.h"

typedef enum {
SWITCH_OFF,
SWITCH_ON,
}SwitchStateEnum_t;

typedef enum{
SW0 = DIO_PIN0,
SW1 = DIO_PIN6,
SW2 = DIO_PIN2,
}SwitchPinEnum_t;

// functions 
 void Switch_Init(volatile uint8 * Port_reg , SwitchPinEnum_t channel);
 SwitchStateEnum_t SwitchStateGet(volatile uint8 * Port_reg , SwitchPinEnum_t channel);




#endif /* SWITCH_H_ */