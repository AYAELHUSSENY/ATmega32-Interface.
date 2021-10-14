/*
 * Led.h
 *
 * Created: 9/29/2021 6:58:34 PM
 *  Author: Dell
 */ 



#ifndef LED_H_
#define LED_H_
#include "ATmega32_Configuration.h"
#include "DIO.h"
#define LED0_1DIR_REG      (PORTC_DIR_REG)
#define LED_OUT_REG        (PORTC_OUTPUT_REG)

typedef enum{
LED_OFF,
LED_ON,
LED_TOGGLE,
}LedStateEnum_t;

typedef enum{
LED0  =DIO_PIN2,
LED1 = DIO_PIN7,
LED2 = DIO_PIN3, 
}LedPinEnum_t;

// functions for led 
void Led_Init( volatile uint8 * Led_reg , LedPinEnum_t LedNumber);
void Led_StateSet(volatile uint8 * Led_reg , LedPinEnum_t LedNumber , LedStateEnum_t State);



#endif /* LED_H_ */