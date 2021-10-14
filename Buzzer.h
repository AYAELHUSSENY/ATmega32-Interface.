/*
 * Buzzer.h
 *
 * Created: 9/29/2021 10:16:30 PM
 *  Author: Dell
 */ 
 #include "ATmega32_Configuration.h"
 #include "DIO.h"
 #include "Led.h"
 #include "Std_Types.h"
 #include "Macros.h"
 #include "Switch.h"

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_DIR_REG    (PORTA_DIR_REG)
#define BUZZER_OUT_REG    (PORTA_OUTPUT_REG)
#define BUZZER_PIN        (DIO_PIN3)


typedef enum {
BUZZER_OFF,
BUZZER_ON,
}BuzzerStateEnum_t;

void Buzzer_Init(void);
void BuzzerStateSet(BuzzerStateEnum_t State);





#endif /* BUZZER_H_ */