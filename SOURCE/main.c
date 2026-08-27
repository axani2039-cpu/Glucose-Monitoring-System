/*
 * main.c
 *
 *  Created on: Aug 26, 2026
 *      Author: ahmed
 */


#define F_CPU 8000000UL
#include <util/delay.h>

/* Shared Libraries */
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

/* Microcontroller Abstraction Layer (MCAL) */
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"
#include "../INCLUDE/MCAL/EXTI/EXTI_INTERFACE.h"
#include "../INCLUDE/MCAL/GL/GL_INTERFACE.h"
#include "../INCLUDE/MCAL/TWI/TWI_INTERFACE.h"

/* Hardware Abstraction Layer (HAL) */
#include "../INCLUDE/HAL/LCD/LCD_INTERFACE.h"
#include "../INCLUDE/HAL/RTC/RTC_INTERFACE.h"
#include "../INCLUDE/HAL/GLUCOSE_SENSOR/GLUCOSE_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"

/* Patient Context State Enum */
typedef enum {
    STATE_FASTING = 0,  // Target: 70 - 100 mg/dL
    STATE_POST_MEAL     // Target: 70 - 140 mg/dL
} PatientState_t;

/* Volatile Globals for Interrupt Safety */
volatile PatientState_t g_patientState = STATE_FASTING;
volatile u8 g_isDoseTime = 0;
volatile u8 g_alarmEnabled = 1; // 1: Active (Default), 0: Muted
RTC_Time_t g_currentTime;

/* Custom Characters Definitions (CGRAM Data) */
u8 Heart_Full[8]  = {0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00}; // Pattern 0
u8 Heart_Empty[8] = {0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00}; // Pattern 1
u8 Arrow_Up[8]    = {0x04, 0x0E, 0x15, 0x04, 0x04, 0x04, 0x04, 0x00}; // Pattern 2
u8 Arrow_Down[8]  = {0x04, 0x04, 0x04, 0x04, 0x15, 0x0E, 0x04, 0x00}; // Pattern 3
u8 Arrow_Right[8] = {0x00, 0x04, 0x02, 0x1F, 0x02, 0x04, 0x00, 0x00}; // Pattern 4
u8 Bell_Icon[8]   = {0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00}; // Pattern 5

/* ISR Callbacks for External Interrupt Buttons */
void ISR_Button_ToggleAlarm(void) {
    g_alarmEnabled = !g_alarmEnabled; // Toggle Alarm ON/OFF
}

void ISR_Button_Fasting(void) {
    g_patientState = STATE_FASTING;
}

void ISR_Button_PostMeal(void) {
    g_patientState = STATE_POST_MEAL;
}

/* Helper Prototypes */
void System_Init(void);
void Display_StartupAnimation(void);
u16 Read_Glucose_Filtered(void);
void Display_RenderScreen(u16 glucoseVal, u8 pulse);
void Handle_AlertsAndLEDs(u16 glucoseVal);
void Check_DoseTime(void);

int main(void) {
    System_Init();
    Display_StartupAnimation();

    /* Set Initial RTC Time for Testing (11:59:50 AM) */
    RTC_Time_t initTime = {00, 00, 10};
    HRTC_voidSetTime(&initTime);

    u16 glucoseValue = 0;
    u8 pulseState = 0;

    while(1) {
        // 1. Read RTC Time and check Doses
        Check_DoseTime();

        // 2. Read Glucose via Moving Average Filter
        glucoseValue = Read_Glucose_Filtered();

        // 3. Render Screen Layout
        pulseState = !pulseState;
        Display_RenderScreen(glucoseValue, pulseState);

        // 4. Process Alerts & LED/Buzzer Outputs
        Handle_AlertsAndLEDs(glucoseValue);

        _delay_ms(300);
    }

    return 0;
}

void System_Init(void) {
    /* Initialize MCAL and Hardware Drivers via Pre-Compile Configurations */
    MDIO_voidInit();
    HLCD_voidInit();
    HGLUCOSE_voidInit();
    HBUZZER_voidInit();
    HRTC_voidInit();

    /* Setup LEDs on PORTD pins (PD5: Green, PD6: Yellow, PD7: Red) */
    MDIO_voidSetPinDirection(PORTD, PIN5, DIO_OUTPUT);
    MDIO_voidSetPinDirection(PORTD, PIN6, DIO_OUTPUT);
    MDIO_voidSetPinDirection(PORTD, PIN7, DIO_OUTPUT);

    /* Load Custom Characters to CGRAM */
    HLCD_voidSendSpecialCharacter(Heart_Full, 0, ROW1, col1);
    HLCD_voidSendSpecialCharacter(Heart_Empty, 1, ROW1, col1);
    HLCD_voidSendSpecialCharacter(Arrow_Up, 2, ROW1, col1);
    HLCD_voidSendSpecialCharacter(Arrow_Down, 3, ROW1, col1);
    HLCD_voidSendSpecialCharacter(Arrow_Right, 4, ROW1, col1);
    HLCD_voidSendSpecialCharacter(Bell_Icon, 5, ROW1, col1);

    /* Setup EXTI INT0 for Alarm Toggle Button (PD2) */
    MEXTI_voidConfig(EXTI0, FALLING_EDGE);
    MEXTI_voidSetCallBack(EXTI0, &ISR_Button_ToggleAlarm);
    MEXTI_voidEnable(EXTI0);

    /* Setup EXTI INT1 for Fasting Button (PD3) */
    MEXTI_voidConfig(EXTI1, FALLING_EDGE);
    MEXTI_voidSetCallBack(EXTI1, &ISR_Button_Fasting);
    MEXTI_voidEnable(EXTI1);

    /* Setup EXTI INT2 for Post-Meal Button (PB2) */
    MEXTI_voidConfig(EXTI2, FALLING_EDGE);
    MEXTI_voidSetCallBack(EXTI2, &ISR_Button_PostMeal);
    MEXTI_voidEnable(EXTI2);

    /* Enable Global Interrupts */
    MGI_voidEnable();
}

void Check_DoseTime(void) {
    HRTC_voidGetTime(&g_currentTime);

    // Check Scheduled Dose Reminders (12:00:00 PM or 09:00:00 PM)
    if ((g_currentTime.Hours == 12 && g_currentTime.Minutes == 0) ||
        (g_currentTime.Hours == 21 && g_currentTime.Minutes == 0)) {
        g_isDoseTime = 1;
    } else {
        g_isDoseTime = 0;
    }
}

void Display_StartupAnimation(void) {
    HLCD_voidClearDisplay();
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString((u8*)" Glucose Monitor");

    HLCD_voidGoToPos(ROW2, col1);
    HLCD_voidSendString((u8*)"Booting [");
    for(u8 i = 0; i < 6; i++) {
        HLCD_voidSendString((u8*)"=");
        _delay_ms(150);
    }
    HLCD_voidSendString((u8*)"]");
    _delay_ms(300);
    HLCD_voidClearDisplay();
}

u16 Read_Glucose_Filtered(void) {
    u32 glucoseSum = 0;
    for(u8 i = 0; i < 10; i++) {
        glucoseSum += HGLUCOSE_u16GetGlucoseValue();
        _delay_ms(2);
    }
    return (u16)(glucoseSum / 10);
}

void Display_RenderScreen(u16 glucoseVal, u8 pulse) {
    HLCD_voidClearDisplay();

    // Line 1: Mode, Glucose Reading, Trend Arrow, Heart Pulse, Bell Icon, Time
    HLCD_voidGoToPos(ROW1, col1);
    HLCD_voidSendString(g_patientState == STATE_FASTING ? (u8*)"F:" : (u8*)"P:");
    HLCD_voidDisplayNumber(glucoseVal);

    u16 minTarget = 70;
    u16 maxTarget = (g_patientState == STATE_FASTING) ? 100 : 140;

    HLCD_voidGoToPos(ROW1, col6);
    if(glucoseVal < minTarget)       HLCD_voidSendData(3); // Arrow Down
    else if(glucoseVal > maxTarget) HLCD_voidSendData(2); // Arrow Up
    else                            HLCD_voidSendData(4); // Arrow Right

    HLCD_voidGoToPos(ROW1, col8);
    HLCD_voidSendData(pulse ? 0 : 1); // Heart Pulse

    HLCD_voidGoToPos(ROW1, col10);
    if(g_alarmEnabled) {
        HLCD_voidSendData(5); // Bell Icon
    } else {
        HLCD_voidSendString((u8*)" ");
    }

    // Display Time (HH:MM) on top right
    HLCD_voidGoToPos(ROW1, col12);
    if(g_currentTime.Hours < 10) HLCD_voidSendString((u8*)"0");
    HLCD_voidDisplayNumber(g_currentTime.Hours);
    HLCD_voidSendString((u8*)":");
    if(g_currentTime.Minutes < 10) HLCD_voidSendString((u8*)"0");
    HLCD_voidDisplayNumber(g_currentTime.Minutes);

    // Line 2: Status Messages & Dose Warnings
    HLCD_voidGoToPos(ROW2, col1);
    if(g_isDoseTime) {
        HLCD_voidSendString((u8*)"!! DOSE TIME !! ");
    } else if(!g_alarmEnabled) {
        HLCD_voidSendString((u8*)"ALARM: OFF      ");
    } else {
        if(glucoseVal < minTarget)       HLCD_voidSendString((u8*)"LOW! Take Sugar ");
        else if(glucoseVal > maxTarget) HLCD_voidSendString((u8*)"HIGH!Drink Water");
        else                            HLCD_voidSendString((u8*)"NORMAL (Good)   ");
    }
}

void Handle_AlertsAndLEDs(u16 glucoseVal) {
    // If Alarm Feature is DISABLED -> Keep All Alert Outputs OFF
    if(!g_alarmEnabled) {
        MDIO_voidSetPinValue(PORTD, PIN5, DIO_LOW);
        MDIO_voidSetPinValue(PORTD, PIN6, DIO_LOW);
        MDIO_voidSetPinValue(PORTD, PIN7, DIO_LOW);
        HBUZZER_voidTurnOff();
        return;
    }

    u8 isLow = (glucoseVal < 70);
    u8 isHigh = (g_patientState == STATE_FASTING) ? (glucoseVal > 100) : (glucoseVal > 140);
    u8 isCritical = (glucoseVal < 50) || (glucoseVal > 200);

    if(g_isDoseTime || isCritical) {
        // Red LED Blinks & Buzzer On for Critical Readings or Dose Time
        MDIO_voidSetPinValue(PORTD, PIN5, DIO_LOW);
        MDIO_voidSetPinValue(PORTD, PIN6, DIO_LOW);

        MDIO_voidSetPinValue(PORTD, PIN7, DIO_HIGH);
        HBUZZER_voidTurnOn();
        _delay_ms(100);
        MDIO_voidSetPinValue(PORTD, PIN7, DIO_LOW);
        HBUZZER_voidTurnOff();
    }
    else if(isLow || isHigh) {
        // Yellow LED Warning
        MDIO_voidSetPinValue(PORTD, PIN5, DIO_LOW);
        MDIO_voidSetPinValue(PORTD, PIN6, DIO_HIGH);
        MDIO_voidSetPinValue(PORTD, PIN7, DIO_LOW);
        HBUZZER_voidTurnOff();
    }
    else {
        // Normal Green LED
        MDIO_voidSetPinValue(PORTD, PIN5, DIO_HIGH);
        MDIO_voidSetPinValue(PORTD, PIN6, DIO_LOW);
        MDIO_voidSetPinValue(PORTD, PIN7, DIO_LOW);
        HBUZZER_voidTurnOff();
    }
}
