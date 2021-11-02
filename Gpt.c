/*
 * Gpt.c
 *
 * Created: 10/15/2021 4:15:59 PM
 *  Author: Dell
 */ 
 #include "ATmega32_Cfg.h"
 #include "GPT.h"
 #include "Macros.h"

 void Gpt_Init(Gpt_ChannelType_Enum Channel , Gpt_ModeType_Enum Mode, Gpt_PrescaleType_Enum Prescale, Gpt_InterruptState_Enum IntState, uint16 CmpValue)
 {
	 switch(Channel)
	 {
		 case GPT0:
					/*!Comment: CLEAR the registers before applying my Configurations*/
					*TIMER0_CTRL_REG = 0x00U;
					switch(Mode)
					{
						case GPT_MODE_NORMAL:
						CLEAR_BIT(*TIMER0_CTRL_REG,3U);
						CLEAR_BIT(*TIMER0_CTRL_REG,6U);
					/*!Comment: Select the Interrupt State*/
						*TIMER_INTERRUPT_MASK_REG |= IntState;
						break;
						case GPT_MODE_CTC:
						SET_BIT(*TIMER0_CTRL_REG,3U);
						CLEAR_BIT(*TIMER0_CTRL_REG,6U);
					/*!Comment: Select the Interrupt State*/
						*TIMER_INTERRUPT_MASK_REG |= IntState<<1;
					/*!Comment: Select the Output compare value (TOP VALUE)*/
						*TIMER0_OUTPUT_COMPARE_REG =(uint8)CmpValue;
						break;
						default:
						break;
					}
					/*!Comment: Select the pre-scale */
					*TIMER0_CTRL_REG |= Prescale;
					/*!Comment: Initialize TCNT0 To start from 0 */
					*TIMER0_COUNTER_REG = 0x00U;		
		 break;
		 case GPT1:
		 break;
		 case GPT2:
		 break;
		 default:
		 break;

	 }
 }
