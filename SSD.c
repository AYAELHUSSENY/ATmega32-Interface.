/*
 * SSD.c
 *
 * Created: 9/29/2021 11:01:11 PM
 *  Author: Dell
 */ 
 #include "SSD.h"
 #include "Macros.h"
#include "DIO.h"
#include <util/delay.h>
const uint8 gau8SSD_arr[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};


void SSD_Init(void){
DioChannelDirectionSet(SSD_CTRL_DIR_REG,SSD1_EN,DIO_OUTPUT);
DioChannelDirectionSet(SSD_CTRL_DIR_REG,SSD2_EN,DIO_OUTPUT);
*SSD_DATA_DIR_REG = 0xF0U;
}
void SSD_NumberDisplay(SSDNumbersEnum_t Num, uint8 SSD_no){
	//Enable the required SSD first 
	switch(SSD_no){

	case SSD1_EN:
	DioChannelWrite(SSD_CTRL_OUT_REG,SSD1_EN,DIO_HIGH);
	DioChannelWrite(SSD_CTRL_OUT_REG,SSD2_EN,DIO_LOW);
	break;

	case SSD2_EN:
	DioChannelWrite(SSD_CTRL_OUT_REG,SSD1_EN,DIO_LOW);
	DioChannelWrite(SSD_CTRL_OUT_REG,SSD2_EN,DIO_HIGH);
	break;
	
	default:
	DioChannelWrite(SSD_CTRL_OUT_REG,SSD1_EN,DIO_LOW);
	DioChannelWrite(SSD_CTRL_OUT_REG,SSD2_EN,DIO_LOW);
	break;

	}
	/* !Comment: This line zero the 4-bits of the data before setting the new value */
	*SSD_DATA_OUT_REG &= ~(0xF0U);
	/* Write the number to the Data pins */
	if(SSD_TYPE == SSD_COMMON_CATHODE)
	{
		*SSD_DATA_OUT_REG |= (Num & 0xF0U) ;
	}
	else
	{
		*SSD_DATA_OUT_REG |= (~Num & 0xF0U);
	}


}

void SSD_NumSet(uint16 Number){
	SSD_NumberDisplay(gau8SSD_arr[(Number%100)/10],SSD2_EN);
	_delay_ms(10);
	SSD_NumberDisplay(gau8SSD_arr[(Number%10)],SSD1_EN);
	_delay_ms(10);

}