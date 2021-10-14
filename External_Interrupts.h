/*
 * External_Interrupts.h
 *
 * Created: 10/8/2021 3:32:12 PM
 *  Author: Dell
 */ 


#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

#define INT0_MODE_SEL_BIT0				(0U)
#define INT0_MODE_SEL_BIT1				(1U)
#define INT1_MODE_SEL_BIT0				(2U)
#define INT1_MODE_SEL_BIT1				(3U)
#define INT2_MODE_SEL_BIT				(6U)

#define INT0_SOURCE_ENABLE_BIT			(6U)
#define INT1_SOURCE_ENABLE_BIT			(7U)
#define	INT2_SOURCE_ENABLE_BIT			(5U)

#define GLOBAL_INTERRUPT_ENABLE_BIT		(7U)

typedef enum{
EXT_INT0,
EXT_INT1,
EXT_INT2
}External_Interrupts_Source_enum;

typedef enum{
EXT_INTERRUPT_LOW_LEVEL,
EXT_INTERRUPT_FALLING_EDGE,
EXT_INTERRUPT_RISING_EDGE,
EXT_INTERRUPT_BOTH_EDGES
}External_Interrupt_Mode_enum;

typedef enum{
GLOBAL_INTERRUPT_DISABLE,
GLOBALE_INTERRUPT_ENABLE
}Global_INTERRUPT_STATE_ENUM;

void External_Interrupts_enable(External_Interrupts_Source_enum Source,External_Interrupt_Mode_enum Mode);
void External_Interrupts_Disable(External_Interrupts_Source_enum Source);
void Global_Interrupt_State_SET(Global_INTERRUPT_STATE_ENUM State);



#endif /* EXTERNAL_INTERRUPTS_H_ */