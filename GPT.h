/*
 * Timers.h
 *
 * Created: 10/15/2021 4:11:43 PM
 *  Author: Dell
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
#include "Std_Types.h"

typedef enum{
GPT0,
GPT1,
GPT2,
}Gpt_ChannelType_Enum;


typedef enum{
GPT_MODE_NORMAL,
GPT_MODE_CTC,
}Gpt_ModeType_Enum;

typedef enum{
GPT_NO_CLK,
GPT_NO_PRESCALE,
GPT_PRESCALE_8,
GPT_PRESCALE_64,
GPT_PRESCALE_256,
SPT_PRESCALE_1024,
}Gpt_PrescaleType_Enum;

typedef enum{
GPT_INTERRUPT_DISABLE,
GPT_INTERRUPT_ENABLE,
}Gpt_InterruptState_Enum;


void Gpt_Init(Gpt_ChannelType_Enum Channel , Gpt_ModeType_Enum Mode, Gpt_PrescaleType_Enum Prescale, Gpt_InterruptState_Enum IntState,uint16 CmpValue);




#endif /* TIMERS_H_ */