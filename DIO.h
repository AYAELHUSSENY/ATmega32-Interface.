/*
 * DIO.h
 *
 * Created: 9/25/2021 10:24:26 PM
 *  Author: Dell
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "Std_Types.h"
typedef enum {
DIO_PIN0,
DIO_PIN1,
DIO_PIN2,
DIO_PIN3,
DIO_PIN4,
DIO_PIN5,
DIO_PIN6,
DIO_PIN7,
} Dio_PinEnum_t;

typedef enum{
DIO_LOW,
DIO_HIGH,
}DioPinStateEnum_t;

typedef enum {
DIO_INPUT,
DIO_OUTPUT,
}DioPinDirectioinEnum_t;


// FUNCTIONS 
void DioChannelDirectionSet(volatile uint8 * Port_reg , Dio_PinEnum_t channel,DioPinDirectioinEnum_t Direction);
void DioChannelWrite(volatile uint8 * Port_reg, Dio_PinEnum_t channel , DioPinStateEnum_t State);
DioPinStateEnum_t DioChannelRead( volatile uint8 * Port_reg ,Dio_PinEnum_t channel);
void DioChannelToggle( volatile uint8 * Port_reg , Dio_PinEnum_t channel);
void DioPortWrite( volatile uint8 * Port_reg , uint8 Value );
uint8 DioPortRead(volatile uint8 * port_reg);








#endif /* DIO_H_ */