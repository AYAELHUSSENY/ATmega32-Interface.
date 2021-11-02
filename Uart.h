/*
 * Uart.h
 *
 * Created: 10/23/2021 4:03:18 PM
 *  Author: Dell
 */ 


#ifndef UART_H_
#define UART_H_

#include "Std_Types.h"
typedef enum
{	
	UART_SYNCH = 0x40U,
	UART_ASYNCH= 0x00U
	
}Uart_OperMode_Type;

typedef enum
{
	UART_NORMAL_SPEED = 0x00U,
	UART_DOUBLE_SPEED = 0x02U,
}Uart_SpeedType;

typedef enum
{
	UART_5_BITS_DATA = 0x00U,
	UART_6_BITS_DATA = 0x02U,
	UART_7_BITS_DATA = 0x04U,
	UART_8_BITS_DATA = 0x06U,
	
}Uart_DataBitsType;

typedef enum
{
	UART_ONE_STOP_BIT  = 0x00U,
	UART_TWO_STOP_BITS = 0x08U,

}Uart_StopBitsType;

typedef enum
{
	UART_PARITY_DISABLE,
	UART_EVEN_PARITY = 0x20U,
	UART_ODD_PARITY  = 0x30U,
}Uart_ParityType;

typedef enum
{
	UART_TX		= 0x08U,
	UART_RX		= 0x10U,
	UART_TX_RX	= 0x18U,
}Uart_CommType;

typedef enum
{
	UART_INT_DISABLE,
	UART_TX_INT	 = 0x40U,
	UART_RX_INT	 = 0x80U,
	UART_UDRE_INT= 0x20U,
}Uart_IntState;

typedef enum
{
	UART_2400_BAUD = 2400,
	UART_4800_BAUD = 4800,
	UART_9600_BAUD = 9600,
	UART_14400_BAUD = 14400,
	UART_19200_BAUD  = 19200,
	UART_28800_BAUD = 28800,
	UART_38400_BAUD = 38400,
	UART_57600_BAUD = 57600,

}Uart_BaudrateType;

void Uart_Init(void);
void Uart_Transmit(uint8 Data);
uint8 Uart_Receive(void);
void Uart_StringTransmit(char * str);



#endif /* UART_H_ */