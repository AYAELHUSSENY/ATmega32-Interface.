/*
 * StepperMotor.h
 *
 * Created: 10/2/2021 2:35:51 PM
 *  Author: Dell
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

//-------------------------------
#include "ATmega32_Configuration.h"
#include "DIO.h"
#include "Std_Types.h"
#include "Macros.h"
#include "Switch.h"
//-------------------------------

#define STEPPER_MOTOR_DIR_REG		(PORTA_DIR_REG)
#define STEPPER_MOTOR_OUTPUT_REG	(PORTA_OUTPUT_REG)

#define STEPPER_MOTOR_IN1_PIN		(DIO_PIN4)
#define STEPPER_MOTOR_IN2_PIN		(DIO_PIN5)
#define STEPPER_MOTOR_IN3_PIN		(DIO_PIN6)
#define STEPPER_MOTOR_IN4_PIN		(DIO_PIN7)

#define  STEPPER_MOTOR_STEP_DELAY_MS	(3U)	

#define  STEPPER_UPPER_PORT			(1U)		//1: UPPER PORT 0 LOWER PORT

// functions prototypes
void StepperMotor_Init(void);
void StepperMotor_TurnCW(void);
void StepperMotor_TurnCCW(void);
































#endif /* STEPPERMOTOR_H_ */