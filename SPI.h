/*
 * SPI.h
 *
 * Created: 10/30/2021 4:14:03 PM
 *  Author: Dell
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "Std_Types.h"
typedef enum
{
	SPI_MASTER_OPERATION  = 0x10U,
	SPI_SLAVE_OPERATION   = 0x00U,

}SPI_OperationTypeEnum;

typedef enum
{
	SPI_LSB_DATA_ORDER = 0x20U	,
	SPI_MSB_DATA_ORDER = 0x00U	,

}SPI_DataOrderType;

typedef enum
{
	SPI_NORMAL_SPEED,
	SPI_DOUBLE_SPEED,
}SPI_SpeedType;

typedef enum 
{
	SPI_INTERRUPT_ENABLE  = 0x80U,
	SPI_INTERRUPT_DISABLE = 0x00U,

}SPI_InterruptStateEnum;

typedef enum
{
	SPI_DIABLE = 0x00U,
	SPI_ENABLE = 0x40U,

}SPI_StateTypeEnum;

typedef enum
{
	SPI_LEAD_RISE_SAMPLE	=0x00,    /* CPOL = 0, CPHA = 0 */
	SPI_LEAD_RISE_SETUP		=0x04,   /* CPOL = 0, CPHA = 1 */
	SPI_LEAD_FALLING_SAMPLE	=0x08,  /* CPOL = 1, CPHA = 0 */
	SPI_LEAD_FALLING_SETUP	=0x0C, /* CPOL = 1, CPHA = 1 */

}Spi_ModeType;

typedef enum
{
	SPI_MASTER_PRESCALER4,
	SPI_MASTER_PRESCALER16,
	SPI_MASTER_PRESCALER64,
	SPI_MASTER_PRESCALER128,
}SPI_PrescaleType;

typedef struct 
{
	SPI_OperationTypeEnum Type;
	SPI_SpeedType Speed;
	SPI_DataOrderType DataOrder;
	SPI_PrescaleType Prescale;
	Spi_ModeType Mode;
	SPI_InterruptStateEnum IntState;

}SPI_ConfigType;

			/*SPI Functions */
void SPI_Init( SPI_ConfigType * SPIConfigPtr);

void SPI_MasterTx( uint8 Data);
void SPI_SlaveTx (uint8 Data);
uint8 SPI_MasterRx(void);
uint8 SPI_SlaveRx(void);
uint8 SPI_Tranceive(uint8 Data);

extern SPI_ConfigType gStrSpi_Configuration;

#endif /* SPI_H_ */