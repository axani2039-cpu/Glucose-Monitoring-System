
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/DIO/DIO_CFG.h"
#include "../INCLUDE/MCAL/DIO/DIO_PRIVATE.h"

#include "../INCLUDE/LIB/BIT_MATH.h"


void DIO_voidSetPinDirection(u8 Copy_u8Port,
u8 Copy_u8Pin,
u8 Copy_u8Direction)
{
switch(Copy_u8Port)
{
case DIO_PORTA:

if(Copy_u8Direction == DIO_OUTPUT)
{
SET_BIT(DDRA, Copy_u8Pin);
}
else
{
CLR_BIT(DDRA, Copy_u8Pin);
}

break;


case DIO_PORTB:

if(Copy_u8Direction == DIO_OUTPUT)
{
SET_BIT(DDRB, Copy_u8Pin);
}
else
{
CLR_BIT(DDRB, Copy_u8Pin);
}

break;


case DIO_PORTC:

if(Copy_u8Direction == DIO_OUTPUT)
{
SET_BIT(DDRC, Copy_u8Pin);
}
else
{
CLR_BIT(DDRC, Copy_u8Pin);
}

break;


case DIO_PORTD:

if(Copy_u8Direction == DIO_OUTPUT)
{
SET_BIT(DDRD, Copy_u8Pin);
}
else
{
CLR_BIT(DDRD, Copy_u8Pin);
}

break;


default:
break;
}
}

void DIO_voidSetPinValue(u8 Copy_u8Port,
u8 Copy_u8Pin,
u8 Copy_u8Value)
{
switch(Copy_u8Port)
{
case DIO_PORTA:

if(Copy_u8Value == DIO_HIGH)
{
SET_BIT(PORTA, Copy_u8Pin);
}
else
{
CLR_BIT(PORTA, Copy_u8Pin);
}

break;


case DIO_PORTB:

if(Copy_u8Value == DIO_HIGH)
{
SET_BIT(PORTB, Copy_u8Pin);
}
else
{
CLR_BIT(PORTB, Copy_u8Pin);
}

break;


case DIO_PORTC:

if(Copy_u8Value == DIO_HIGH)
{
SET_BIT(PORTC, Copy_u8Pin);
}
else
{
CLR_BIT(PORTC, Copy_u8Pin);
}

break;


case DIO_PORTD:

if(Copy_u8Value == DIO_HIGH)
{
SET_BIT(PORTD, Copy_u8Pin);
}
else
{
CLR_BIT(PORTD, Copy_u8Pin);
}

break;


default:
break;
}
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port,
u8 Copy_u8Pin)
{
u8 Local_u8Value = DIO_LOW;

switch(Copy_u8Port)
{
case DIO_PORTA:

Local_u8Value = GET_BIT(PINA, Copy_u8Pin);

break;


case DIO_PORTB:

Local_u8Value = GET_BIT(PINB, Copy_u8Pin);

break;


case DIO_PORTC:

Local_u8Value = GET_BIT(PINC, Copy_u8Pin);

break;


case DIO_PORTD:

Local_u8Value = GET_BIT(PIND, Copy_u8Pin);

break;


default:
break;
}

return Local_u8Value;
}

void DIO_voidSetPortDirection(u8 Copy_u8Port,
u8 Copy_u8Direction)
{
switch(Copy_u8Port)
{
case DIO_PORTA:
DDRA = Copy_u8Direction;
break;

case DIO_PORTB:
DDRB = Copy_u8Direction;
break;

case DIO_PORTC:
DDRC = Copy_u8Direction;
break;

case DIO_PORTD:
DDRD = Copy_u8Direction;
break;

default:
break;
}
}

void DIO_voidSetPortValue(u8 Copy_u8Port,
u8 Copy_u8Value)
{
switch(Copy_u8Port)
{
case DIO_PORTA:
PORTA = Copy_u8Value;
break;

case DIO_PORTB:
PORTB = Copy_u8Value;
break;

case DIO_PORTC:
PORTC = Copy_u8Value;
break;

case DIO_PORTD:
PORTD = Copy_u8Value;
break;

default:
break;
}
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port)
{
u8 Local_u8Value = 0;

switch(Copy_u8Port)
{
case DIO_PORTA:
Local_u8Value = PINA;
break;

case DIO_PORTB:
Local_u8Value = PINB;
break;

case DIO_PORTC:
Local_u8Value = PINC;
break;

case DIO_PORTD:
Local_u8Value = PIND;
break;

default:
break;
}

return Local_u8Value;
}
