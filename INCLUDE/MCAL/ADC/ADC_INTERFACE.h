/*
 * ADC_INTERFACE.h
 *
 *  Created on: Aug 26, 2026
 *      Author: lenovo
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_


typedef enum
{
	ADC_CHANNEL_0 = 0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7

} ADC_Channel_t;


typedef enum
{
	ADC_VREF_AREF = 0,
	ADC_VREF_AVCC,
	ADC_VREF_INTERNAL_2_56V

} ADC_VREF_t;


typedef enum
{
	ADC_RIGHT_ADJUST = 0,
	ADC_LEFT_ADJUST

} ADC_Adjustment_t;


typedef enum
{
	ADC_PRESCALER_2 = 2,
	ADC_PRESCALER_4 = 4,
	ADC_PRESCALER_8 = 8,
	ADC_PRESCALER_16 = 16,
	ADC_PRESCALER_32 = 32,
	ADC_PRESCALER_64 = 64,
	ADC_PRESCALER_128 = 128

} ADC_Prescaler_t;


void MADC_voidInit(void);

u16 MADC_u16GetDigitalValue(ADC_Channel_t A_ADC_Channel);



#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
