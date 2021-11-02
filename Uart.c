/*
 * abdelaziz.c
 *
 * Created: 10/24/2021 1:46:19 PM
 *  Author: Dell
 */ 

#include "Uart.h"
#include "ATmega32_Cfg.h"
#include "Macros.h"

void Uart_Init(void)
{
	uint16 u16LocalUartBaudValue = 0U;
	/* Clear Configuration registers */
	*UART_CTRL_STATUS_A_REG = 0x00U;
	*UART_CTRL_STATUS_B_REG = 0x00U;
	*UART_CTRL_STATUS_C_REG = 0x00U;
	

	*UART_CTRL_STATUS_C_REG |= UART_ASYNCH;
    *UART_CTRL_STATUS_C_REG |= (1U << 7U) | UART_8_BITS_DATA;  /* You have to set URSEL when selecting databits */
	*UART_CTRL_STATUS_C_REG |= UART_ONE_STOP_BIT;
	*UART_CTRL_STATUS_C_REG |= UART_PARITY_DISABLE;
	*UART_CTRL_STATUS_C_REG |= UART_NORMAL_SPEED;
	*UART_CTRL_STATUS_B_REG |= UART_TX;
	*UART_CTRL_STATUS_B_REG |= UART_INT_DISABLE;
	/* To write to BAUD HIGH REG */
	CLEAR_BIT(*UART_CTRL_STATUS_C_REG, 7U);
	u16LocalUartBaudValue = (uint16)(F_CPU/ (16.0 * UART_9600_BAUD)) - 1U;
	*UART_BAUDRATE_HIGH_REG = (uint8)(u16LocalUartBaudValue >> 8);
	*UART_BAUDRATE_LOW_REG = (uint8) u16LocalUartBaudValue;	
}
void Uart_Transmit(uint8 Data)
{
	/* Wait until UDRE is equal to 1 */
	while(READ_BIT(*UART_CTRL_STATUS_A_REG, 5) == 0U)
	{
		/* Do Nothing */
	}	
	*UART_DATA_REG = Data;

}
uint8 Uart_Receive(void)
{
	uint8 u8LocalReceiveValue = 0U;
	/* Wait until RXC is equal to 1 */
	while(READ_BIT(*UART_CTRL_STATUS_A_REG, 7U) == 0U)
	{
		/* Do Nothing */
	}
	u8LocalReceiveValue = *UART_DATA_REG;
	return (u8LocalReceiveValue);
}
void Uart_StringTransmit(char *str)
{
	while (*str != '\0')
	{
		Uart_Transmit(*str);
		str++;
	}
}