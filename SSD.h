/*
 * SSD.h
 *
 * Created: 9/29/2021 10:54:26 PM
 *  Author: Dell
 */ 


#ifndef SSD_H_
#define SSD_H_
#include "ATmega32_Configuration.h"
#include "DIO.h"
#include "Std_Types.h"

#define SSD_DATA_DIR_REG  (PORTA_DIR_REG)
#define SSD_DATA_OUT_REG  (PORTA_OUTPUT_REG)

#define SSD_CTRL_DIR_REG  (PORTB_DIR_REG)
#define SSD_CTRL_OUT_REG  (PORTB_OUTPUT_REG)

#define SSD1_EN           (DIO_PIN1)
#define SSD2_EN           (DIO_PIN2)

#define SSD_TYPE          (SSD_COMMON_CATHODE)


typedef enum{
ZERO = 0x00U,
ONE = 0x10U,
TWO = 0x20U,
THREE = 0x30U,
FOUR = 0x40U,
FIVE = 0x50U,
SIX = 0x60U,
SEVEN = 0x70U,
EIGHT = 0x80U,
NINE = 0x90U,
}SSDNumbersEnum_t;

typedef enum
{
	SSD_COMMON_CATHODE,
	SSD_COMMON_ANODE
}SSD_TypeEnum_t;

void SSD_Init(void);
void SSD_NumberDisplay(SSDNumbersEnum_t Num, uint8 SSD_no);
void SSD_NumSet(uint16 Number);




#endif /* SSD_H_ */