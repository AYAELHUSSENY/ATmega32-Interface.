/*
 * External_Interrupts.c
 *
 * Created: 10/8/2021 3:32:36 PM
 *  Author: Dell
 */ 
 #include "Std_Types.h"
#include "ATmega32_Cfg.h"
#include "External_Interrupts.h"
#include "Macros.h"

static void EXTERNAL_INTERRUPT_MODE_SET(External_Interrupt_Mode_enum Mode,uint8 bit0 , uint8 bit1);

 void External_Interrupts_enable(External_Interrupts_Source_enum Source,External_Interrupt_Mode_enum Mode)
 {
	switch(Source)
	{
		case EXT_INT0:
 // CONFIGURE INT0 MODE
 EXTERNAL_INTERRUPT_MODE_SET(Mode,INT0_MODE_SEL_BIT0,INT0_MODE_SEL_BIT1);
 // ENABLE SOURCE INTERRUPT
 SET_BIT(*GENRAL_INT_CTRL_REG,INT0_SOURCE_ENABLE_BIT);
 break;

 case EXT_INT1:
 //CONFIGURATION INT1 MODE
 EXTERNAL_INTERRUPT_MODE_SET(Mode,INT1_MODE_SEL_BIT0,INT1_MODE_SEL_BIT1);
 // ENABLE INT1 SOURCE
 SET_BIT(*GENRAL_INT_CTRL_REG,INT0_SOURCE_ENABLE_BIT);
 break;

 case EXT_INT2:
 //CONFIGURATION INT2 MODE
 switch(Mode){
 	 case EXT_INTERRUPT_FALLING_EDGE:
	 CLEAR_BIT(*MCU_CTRL_STATUS_REG,INT2_MODE_SEL_BIT);
	 break;
	 case EXT_INTERRUPT_RISING_EDGE:
	 SET_BIT(*MCU_CTRL_STATUS_REG,INT2_MODE_SEL_BIT);
	 break;
 }
 //ENABLE INT2 INTERRUPT SOURCE 
 SET_BIT(*GENRAL_INT_CTRL_REG,INT2_SOURCE_ENABLE_BIT);
 break;

 default:
 break;
 }

 }

 void External_Interrupts_Disable(External_Interrupts_Source_enum Source){
	switch(Source){

	case EXT_INT0:
	CLEAR_BIT(*GENRAL_INT_CTRL_REG,INT0_SOURCE_ENABLE_BIT);
	break;

	case EXT_INT1:
	CLEAR_BIT(*GENRAL_INT_CTRL_REG,INT1_SOURCE_ENABLE_BIT);
	break;

	case EXT_INT2:
	CLEAR_BIT(*GENRAL_INT_CTRL_REG,INT2_SOURCE_ENABLE_BIT);
	break;
	default:
	break;
	}
 }
 void Global_Interrupt_State_SET(Global_INTERRUPT_STATE_ENUM State){
 switch(State){
 case GLOBAL_INTERRUPT_DISABLE:
 CLEAR_BIT(*AVR_STATUS_REG,GLOBAL_INTERRUPT_ENABLE_BIT);
 break;
 case GLOBALE_INTERRUPT_ENABLE:
 SET_BIT(*AVR_STATUS_REG,GLOBAL_INTERRUPT_ENABLE_BIT);
 break;
 default:
 break;
 }

 }
 static void EXTERNAL_INTERRUPT_MODE_SET(External_Interrupt_Mode_enum Mode,uint8 bit0 , uint8 bit1){
 switch(Mode){

	 case EXT_INTERRUPT_LOW_LEVEL:
	 CLEAR_BIT(*MCU_CTRL_REG,bit0);
	 CLEAR_BIT(*MCU_CTRL_REG,bit1);
	 break;

	 case EXT_INTERRUPT_FALLING_EDGE:
	 CLEAR_BIT(*MCU_CTRL_REG,bit0);
	 SET_BIT(*MCU_CTRL_REG,bit1);
	 break;

	 case EXT_INTERRUPT_RISING_EDGE:
	 SET_BIT(*MCU_CTRL_REG,bit0);
	 SET_BIT(*MCU_CTRL_REG,bit1);
	 break;

	 case EXT_INTERRUPT_BOTH_EDGES:
	 SET_BIT(*MCU_CTRL_REG,bit0);
	 CLEAR_BIT(*MCU_CTRL_REG,bit1);
	 break;
	 default:
	 break;
 }
 }

 
 
