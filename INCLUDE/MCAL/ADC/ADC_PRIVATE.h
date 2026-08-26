#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

/* ADC Registers */

#define ADMUX   *((volatile u8*)0x27)
#define ADCSRA  *((volatile u8*)0x26)
#define ADCH    *((volatile u8*)0x25)
#define ADCL    *((volatile u8*)0x24)


/* ADMUX Bits */

#define REFS1   7
#define REFS0   6
#define ADLAR   5

#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0


/* ADCSRA Bits */

#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3

#define ADPS2   2
#define ADPS1   1
#define ADPS0   0


#endif
