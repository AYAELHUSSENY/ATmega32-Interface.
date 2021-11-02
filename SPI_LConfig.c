/*
 * SPI_LConfig.c
 *
 * Created: 10/30/2021 5:20:58 PM
 *  Author: Dell
 */ 

 #include "SPI.h"

 SPI_ConfigType gStrSpi_Configuration = 
 {
	SPI_MASTER_OPERATION,
	SPI_NORMAL_SPEED,
	SPI_LSB_DATA_ORDER,
	SPI_MASTER_PRESCALER16,
	SPI_LEAD_RISE_SETUP,
	SPI_INTERRUPT_DISABLE,
 };
