#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_PRIVATE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_CFG.h"

void HBUZZER_voidInit(void)
{
    MDIO_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_OUTPUT);
}

void HBUZZER_voidTurnOn(void)
{
    MDIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH);
}

void HBUZZER_voidTurnOff(void)
{
    MDIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW);
}

void HBUZZER_voidToggle(void)
{
    MDIO_voidTogglePinValue(BUZZER_PORT, BUZZER_PIN);
}
