/*
 * SPI.c
 *
 * Created: 10/30/2021 4:14:16 PM
 *  Author: Dell
 */ 
 #include "Dio.h"
 #include "ATmega32_Cfg.h"
 #include "Macros.h"
 #include "SPI.h"

 void SPI_Init( SPI_ConfigType * SPIConfigPtr)
 {
	switch(SPIConfigPtr -> Type)
	{
		case SPI_MASTER_OPERATION :
		Dio_ChannelDirectionSet(PORTB_DIR_REG,DIO_PIN4,DIO_OUTPUT);
		Dio_ChannelDirectionSet(PORTB_DIR_REG,DIO_PIN5,DIO_OUTPUT);
		Dio_ChannelDirectionSet(PORTB_DIR_REG,DIO_PIN7,DIO_OUTPUT);
		Dio_ChannelDirectionSet(PORTB_DIR_REG,DIO_PIN6,DIO_INPUT);
		break;
		case SPI_SLAVE_OPERATION:
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN4, DIO_INPUT); //SS
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN5, DIO_INPUT); //MOSI
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN7, DIO_INPUT); //SCK
		Dio_ChannelDirectionSet(PORTB_DIR_REG, DIO_PIN6, DIO_OUTPUT); //MISO
		break;
		default:
		break;
	}
	/* ! Clear registers before config*/
	*SPI_CTRL_REG = 0x00U;
	*SPI_STATUS_REG = 0x00U;
	
	*SPI_STATUS_REG |= SPIConfigPtr ->Speed;
	*SPI_CTRL_REG   |= SPIConfigPtr ->Type;
	*SPI_CTRL_REG   |= SPIConfigPtr ->Mode;
	*SPI_CTRL_REG   |= SPIConfigPtr ->DataOrder;
	*SPI_CTRL_REG   |= SPIConfigPtr ->Prescale;
	*SPI_CTRL_REG   |= SPIConfigPtr ->IntState;

	*SPI_CTRL_REG   |= SPI_ENABLE;



 }

 

 void SPI_MasterTx( uint8 Data)
 {
		uint8 u8LocalFlushReg = 0U;
		*SPI_DATA_REG = Data;
		while(READ_BIT(*SPI_STATUS_REG,7) == 0 )
		{
				//DO nothing 
		}
	u8LocalFlushReg = *SPI_DATA_REG; // to clear data reg ghareba bas it's okay :D
 }
 uint8 SPI_MasterRx(void)
 {
		uint8 u8LocalRecData = 0U ;
		*SPI_DATA_REG = 0xFFU; // dummy data
		while(READ_BIT(*SPI_STATUS_REG,7) == 0 )
		{
			//DO Nothing 
		}
		u8LocalRecData = *SPI_DATA_REG;
		return u8LocalRecData;
 }

 void SPI_SlaveTx (uint8 Data)
 {
	uint8 u8LocalFlushReg = 0U;
	*SPI_DATA_REG = Data;
	while(READ_BIT(*SPI_STATUS_REG,7) == 0 )
	{
		//DO nothing
	}
	u8LocalFlushReg = *SPI_DATA_REG; // to clear data reg ghareba bas it's okay :D
 }
 
 uint8 SPI_SlaveRx(void)
 { 
		/*!COMMENT : Same function as Master but without sending dummy data */
	uint8 u8LocalRecData = 0U ;
	while(READ_BIT(*SPI_STATUS_REG,7) == 0 )
	{
		//DO Nothing
	}
	u8LocalRecData = *SPI_DATA_REG;
	return u8LocalRecData;
 }

 uint8 SPI_Tranceive(uint8 Data)
 {
	uint8 u8LocalRecData = 0U ;
	*SPI_DATA_REG = Data;
	while(READ_BIT(*SPI_STATUS_REG,7) == 0 )
	{
		//DO Nothing
	}
	u8LocalRecData = *SPI_DATA_REG;
	return u8LocalRecData;
	
 }