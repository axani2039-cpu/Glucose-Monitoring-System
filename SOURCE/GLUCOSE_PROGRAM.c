/*
 * GLUCOSE_PROGRAM.c
 *
 *  Created on: Aug 26, 2026
 *      Author: lenovo
 */

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"

#include "../INCLUDE/MCAL/ADC/ADC_INTERFACE.h"

#include "../INCLUDE/HAL/GLUCOSE_SENSOR/GLUCOSE_INTERFACE.h"
#include "../INCLUDE/HAL/GLUCOSE_SENSOR/GLUCOSE_CFG.h"
#include "../INCLUDE/HAL/GLUCOSE_SENSOR/GLUCOSE_PRIVATE.h"


void HGLUCOSE_voidInit(void)
{
    MADC_voidInit();
}


u16 HGLUCOSE_u16GetGlucoseValue(void)
{
    u16 Local_u16ADCValue;
    u16 Local_u16GlucoseValue;

    Local_u16ADCValue = MADC_u16GetDigitalValue(GLUCOSE_SENSOR_ADC_CHANNEL);

    Local_u16GlucoseValue = GLUCOSE_SENSOR_MAP(Local_u16ADCValue);

    return Local_u16GlucoseValue;
}
