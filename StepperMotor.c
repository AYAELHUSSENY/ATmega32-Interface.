/*
 * StepperMotor.c
 *
 * Created: 10/2/2021 2:36:05 PM
 *  Author: Dell
 */ 
 // function implementation
 #include "StepperMotor.h"
 #include "Std_Types.h"
 #include <util/delay.h>
 #define  STEPPER_MOTOR_COILS_NUMBER	(4U)

 #if STEPPER_UPPER_PORT
 uint8 gau8StepperRotation[STEPPER_MOTOR_COILS_NUMBER] = {0x10,0x20,0x40,0x80};
 #else
 uint8 gau8StepperRotation[STEPPER_MOTOR_COILS_NUMBER] = {0x01,0x02,0x04,0x08};
 #endif




 void StepperMotor_Init(void){
 DioChannelDirectionSet(STEPPER_MOTOR_DIR_REG,STEPPER_MOTOR_IN1_PIN,DIO_OUTPUT);
 DioChannelDirectionSet(STEPPER_MOTOR_DIR_REG,STEPPER_MOTOR_IN2_PIN,DIO_OUTPUT);
 DioChannelDirectionSet(STEPPER_MOTOR_DIR_REG,STEPPER_MOTOR_IN3_PIN,DIO_OUTPUT);
 DioChannelDirectionSet(STEPPER_MOTOR_DIR_REG,STEPPER_MOTOR_IN4_PIN,DIO_OUTPUT);
 }

 void StepperMotor_TurnCW(void){
		uint8 u8LocalLoopIndex;
		for(u8LocalLoopIndex = 0U; u8LocalLoopIndex < STEPPER_MOTOR_COILS_NUMBER; u8LocalLoopIndex++){
		#if STEPPER_UPPER_PORT
		*STEPPER_MOTOR_OUTPUT_REG &= 0x0FU;
		#else
		*STEPPER_MOTOR_OUTPUT_REG &= 0xF0U;
		#endif
		*STEPPER_MOTOR_OUTPUT_REG |= gau8StepperRotation[u8LocalLoopIndex];
		_delay_ms(STEPPER_MOTOR_STEP_DELAY_MS);
				
		}
 }


 void StepperMotor_TurnCCW(void){
 sint8 s8LocalLoopIndex;

 for(s8LocalLoopIndex = (STEPPER_MOTOR_COILS_NUMBER-1); s8LocalLoopIndex >= 0 ; s8LocalLoopIndex--){
	 #if STEPPER_UPPER_PORT
	 *STEPPER_MOTOR_OUTPUT_REG &= 0x0FU;
	 #else
	 *STEPPER_MOTOR_OUTPUT_REG &= 0xF0U;
	 #endif
	 *STEPPER_MOTOR_OUTPUT_REG |= gau8StepperRotation[s8LocalLoopIndex];
	 _delay_ms(STEPPER_MOTOR_STEP_DELAY_MS);
	 }

 }

