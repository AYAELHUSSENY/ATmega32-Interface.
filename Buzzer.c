/*
 * Buzzer.c
 *
 * Created: 9/29/2021 10:16:43 PM
 *  Author: Dell
 */ 
 #include "Buzzer.h"

 void Buzzer_Init(void){
	DioChannelDirectionSet(BUZZER_DIR_REG,BUZZER_PIN,DIO_OUTPUT);
 }

 void BuzzerStateSet(BuzzerStateEnum_t State){
 DioChannelWrite(BUZZER_OUT_REG,BUZZER_PIN,State);
 }
