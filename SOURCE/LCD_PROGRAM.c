#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include <util/delay.h>

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/LCD/LCD_PRIVATE.h"
#include "../INCLUDE/HAL/LCD/LCD_CFG.h"

static void HLCD_voidSendEnablePulse(void) {
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);
    _delay_ms(2);
}

static void HLCD_voidWrite4Bits(u8 copy_u8Data) {
    MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(copy_u8Data, 0));
    MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(copy_u8Data, 1));
    MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(copy_u8Data, 2));
    MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(copy_u8Data, 3));
    HLCD_voidSendEnablePulse();
}

void HLCD_voidInit(void) {
    _delay_ms(40);

    MDIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
    MDIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
    MDIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_OUTPUT);

    MDIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D4_PIN, DIO_OUTPUT);
    MDIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D5_PIN, DIO_OUTPUT);
    MDIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D6_PIN, DIO_OUTPUT);
    MDIO_voidSetPinDirection(LCD_DATA_PORT, LCD_D7_PIN, DIO_OUTPUT);

    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_LOW);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

    HLCD_voidWrite4Bits(0x03);
    _delay_ms(5);
    HLCD_voidWrite4Bits(0x03);
    _delay_us(150);
    HLCD_voidWrite4Bits(0x03);
    HLCD_voidWrite4Bits(0x02);

    HLCD_voidSendCommand(0x28);
    _delay_ms(1);
    HLCD_voidSendCommand(0x0C);
    _delay_ms(1);
    HLCD_voidSendCommand(0x01);
    _delay_ms(2);
    HLCD_voidSendCommand(0x06);
    _delay_ms(1);
}

void HLCD_voidSendCommand(u8 copy_u8Command) {
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_LOW);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

    HLCD_voidWrite4Bits(copy_u8Command >> 4);
    HLCD_voidWrite4Bits(copy_u8Command & 0x0F);
}

void HLCD_voidSendData(u8 copy_u8Data) {
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_HIGH);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

    HLCD_voidWrite4Bits(copy_u8Data >> 4);
    HLCD_voidWrite4Bits(copy_u8Data & 0x0F);
}

void HLCD_voidClearDisplay(void) {
    HLCD_voidSendCommand(0x01);
    _delay_ms(2);
}

void HLCD_voidSendString(u8 *copy_u8String) {
    u8 Local_u8Iterator = 0;
    while (copy_u8String[Local_u8Iterator] != '\0') {
        HLCD_voidSendData(copy_u8String[Local_u8Iterator]);
        Local_u8Iterator++;
    }
}


void HLCD_voidDisplayNumber(u32 copy_u8Number) {
    u8 Local_u8Arr[10];
    s8 Local_s8Iterator = 0;

    if (copy_u8Number == 0) {
        HLCD_voidSendData('0');
        return;
    }

    while (copy_u8Number != 0) {
        Local_u8Arr[Local_s8Iterator] = (copy_u8Number % 10) + '0';
        copy_u8Number /= 10;
        Local_s8Iterator++;
    }

    Local_s8Iterator--;
    while (Local_s8Iterator >= 0) {
        HLCD_voidSendData(Local_u8Arr[Local_s8Iterator]);
        Local_s8Iterator--;
    }
}

void HLCD_voidGoToPos(u8 copy_u8Row, u8 copy_u8Col) {
    u8 Local_u8Address = 0;
    switch (copy_u8Row) {
        case ROW1:
            Local_u8Address = copy_u8Col;
            break;
        case ROW2:
            Local_u8Address = copy_u8Col + 0x40;
            break;
    }
    HLCD_voidSendCommand(Local_u8Address + 128);
}

void HLCD_voidSendSpecialCharacter(u8 *copy_u8Pattern, u8 copy_u8PatternNum, u8 copy_u8Row, u8 copy_u8Col) {
    u8 Local_u8CGRAMAddress = copy_u8PatternNum * 8;
    HLCD_voidSendCommand(Local_u8CGRAMAddress + 64);

    for (u8 Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++) {
        HLCD_voidSendData(copy_u8Pattern[Local_u8Iterator]);
    }

    HLCD_voidGoToPos(copy_u8Row, copy_u8Col);
    HLCD_voidSendData(copy_u8PatternNum);
}
