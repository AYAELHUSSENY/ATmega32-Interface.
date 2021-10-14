/*
 * ADC.h
 *
 * Created: 10/14/2021 7:05:22 PM
 *  Author: Dell
 */ 
 #include "Std_Types.h"
 #define  ADC_START_CONV_BIT	6U
 #define ADC_INTERRUPT_FLAG_BIT 4U

 typedef enum 
 {
	 ADC_Channel0,
	 ADC_Channel1,
	 ADC_Channel2,
	 ADC_Channel3,
	 ADC_Channel4,
	 ADC_Channel5,
	 ADC_Channel6,
	 ADC_Channel7,
  }ADC_ChannelsEnum_t;

typedef enum
{
	ADC_Voltage_Selection_AREF = 0x00U,
	ADC_Voltage_Selection_AVCC = 0x40U,
	ADC_Voltage_Selection_2_56V = 0xC0,
}ADC_Voltage_SelectionEnum_t;

typedef enum
{
	ADC_Right_Alignment = 0x00U,
	ADC_Left_Alignment = 0x20U,
}ADC_Alignment_TypeEnum;

typedef enum
{
	ADC_State_Enable  = 0x80U,
	ADC_State_Disable = 0x00U,
}ADC_StateEnum;

typedef enum
{
	ADC_Interrupt_Enable = 0x08U,
	ADC_Interrupt_Disable= 0x00U,
}ADC_Interrupt_StateEnum;

typedef enum
{
	ADC_Prescale_2 = 0x01U,
	ADC_Prescale_4,
	ADC_Prescale_8,
	ADC_Prescale_16,
	ADC_Prescale_32,
	ADC_Prescale_64,
	ADC_Prescale_128,
}ADC_Prescale_TypeEnum;

typedef enum
{
	ADC_ANALOG_COMPARATOR       = 0x20U,
	ADC_EXT_INTERRUPT0          = 0x40U,
	ADC_TIMER0_CMP_MATCH        = 0x60U,
	ADC_TIMER0_OVF              = 0x80U,
	ADCE_TIMER1_CMP_MATCH_B     = 0xA0U,
	ADC_TIMER1_OVF              = 0xC0U,
	ADC_TIMER1_CAPTURE_EVENT    = 0xE0U,
}ADC_Source_Trigger_TypeEnum;

typedef enum
{
	ADC_EIGHT_BIT,
	ADC_TEN_BIT
}Adc_ResolutionType;

typedef enum
{
	ADC_CON_MODE_CONTINUOUS     = 0x00U,
	ADC_CON_MODE_ONESHOT        = 0x01U,
	ADC_CON_MODE_TRIGGER        = 0x02U
}Adc_ConModeType;

 typedef struct
 {
	 ADC_Voltage_SelectionEnum_t VoltageSelection;
	 ADC_Alignment_TypeEnum      AlignmentSelection;
	 ADC_Interrupt_StateEnum	 InterruptState;
	 ADC_Prescale_TypeEnum		 Prescale;
	 ADC_Source_Trigger_TypeEnum SourceTrigger;
	 Adc_ConModeType			 ConvMode;
 }ADC_ConfigurationsType;

  extern  ADC_ConfigurationsType ADC_Config;

  void ADC_Init(ADC_ConfigurationsType *ADC_Config);
  uint16 ADC_Read(ADC_ChannelsEnum_t channel);

