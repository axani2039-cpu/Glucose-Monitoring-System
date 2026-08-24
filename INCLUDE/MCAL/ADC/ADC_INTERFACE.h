#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


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


void MADC_voidInit(void);

u16 MADC_u16GetDigitalValue(ADC_Channel_t A_ADC_Channel);


#endif
