#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_CFG.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_PRIVATE.h"

#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"


void BUZZER_voidInit(void)
{
DIO_voidSetPinDirection(
BUZZER_PORT,
BUZZER_PIN,
DIO_OUTPUT
);

BUZZER_voidOff();
}

void BUZZER_voidOn(void)
{
DIO_voidSetPinValue(
BUZZER_PORT,
BUZZER_PIN,
DIO_HIGH
);
}

void BUZZER_voidOff(void)
{
DIO_voidSetPinValue(
BUZZER_PORT,
BUZZER_PIN,
DIO_LOW
);
}
