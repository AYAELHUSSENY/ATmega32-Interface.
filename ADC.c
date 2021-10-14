/*
 * ADC.c
 *
 * Created: 10/14/2021 7:05:13 PM
 *  Author: Dell
 */ 
 #include "ATmega32_Cfg.h"
 #include "ADC.h"
 #include "Macros.h"
 #include "Std_Types.h"


   void ADC_Init(ADC_ConfigurationsType *ADC_Config){
		/*!Comment: Clear Registers to apply my configurations */
		*ADC_MUX_SELECTION_REG = 0X00U;
		/*!Comment:Reference Selection*/
		*ADC_MUX_SELECTION_REG |= ADC_Config->VoltageSelection;
		/*!Comment: Select Result Adjustment*/
		*ADC_MUX_SELECTION_REG |= ADC_Config->AlignmentSelection;
		/*!Comment: Clear the Control and Status Register to apply my Config*/
		*ADC_CTRL_AND_STATUS_REG = 0X00U;
		/*!Comment:Disable Interrupt*/
		*ADC_CTRL_AND_STATUS_REG |= ADC_Config->InterruptState;
		/*!Comment: Select Conversion Mode*/
		*ADC_CTRL_AND_STATUS_REG |= ADC_Config->ConvMode;
		/*!Comment: Select ADC Pre-Scaler*/
		*ADC_CTRL_AND_STATUS_REG |= ADC_Config->Prescale;
		/*Comment: enable ADC module after performing these configurations*/
		*ADC_CTRL_AND_STATUS_REG |= ADC_State_Enable;
   }
     uint16 ADC_Read(ADC_ChannelsEnum_t channel){
	  uint16 u16LocalResult = 0;
	 /*!Comment: Clear bits of channel selection first in ADMUX register*/
	 *ADC_MUX_SELECTION_REG &= 0xE0U ;
	 /*!Comment: Select the channel*/
	 *ADC_MUX_SELECTION_REG |= channel;
	 /*!Comment: ADC Start Conversion */
	SET_BIT(*ADC_CTRL_AND_STATUS_REG,ADC_START_CONV_BIT);
	 /*!Comment: Check if the Conversion is finished*/
	 while(READ_BIT(*ADC_CTRL_AND_STATUS_REG,ADC_INTERRUPT_FLAG_BIT) == 0 ){
	 //DO nothing because the conversion is still in progress
	 }
	 u16LocalResult = *(uint16*)ADC_DATA_LOW_REG;
	 /*!Comment: Clear ADC Interrupt Flag */
	 SET_BIT(*ADC_CTRL_AND_STATUS_REG,ADC_INTERRUPT_FLAG_BIT);
	 return u16LocalResult;

}
