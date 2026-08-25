#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "ADC_CFG.h"


void MADC_voidInit(void)
{
	/* Select Voltage Reference */

#if ADC_VREF_SELECTION == ADC_VREF_AVCC

	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);

#elif ADC_VREF_SELECTION == ADC_VREF_INTERNAL

	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);

#endif


	/* Right Adjust Result */

	CLR_BIT(ADMUX, ADLAR);


	/* Enable ADC */

	SET_BIT(ADCSRA, ADEN);


	/* Disable Auto Trigger */

	CLR_BIT(ADCSRA, ADATE);


	/* Disable ADC Interrupt */

	CLR_BIT(ADCSRA, ADIE);


	/* Select ADC Prescaler */

#if ADC_PRESCALER == ADC_PRESCALER_2

	CLR_BIT(ADCSRA, ADPS2);
	CLR_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS0);

#elif ADC_PRESCALER == ADC_PRESCALER_4

	CLR_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS0);

#elif ADC_PRESCALER == ADC_PRESCALER_8

	CLR_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS0);

#elif ADC_PRESCALER == ADC_PRESCALER_16

	SET_BIT(ADCSRA, ADPS2);
	CLR_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS0);

#elif ADC_PRESCALER == ADC_PRESCALER_32

	SET_BIT(ADCSRA, ADPS2);
	CLR_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS0);

#elif ADC_PRESCALER == ADC_PRESCALER_64

	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	CLR_BIT(ADCSRA, ADPS0);

#elif ADC_PRESCALER == ADC_PRESCALER_128

	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS0);

#endif
}


u16 MADC_u16GetDigitalValue(ADC_Channel_t A_ADC_Channel)
{
	u8 Local_u8Low;
	u8 Local_u8High;

	u16 Local_u16Result;


	/* Select ADC Channel */

	ADMUX &= 0b11100000;

	ADMUX |= A_ADC_Channel;


	/* Start Conversion */

	SET_BIT(ADCSRA, ADSC);


	/* Wait Until Conversion Complete */

	while(GET_BIT(ADCSRA, ADIF) == 0);


	/* Clear ADC Flag */

	SET_BIT(ADCSRA, ADIF);


	/* Read ADC Result */

	Local_u8Low = ADCL;

	Local_u8High = ADCH;


	Local_u16Result =
			((u16)Local_u8High << 8) | Local_u8Low;


	return Local_u16Result;
}
