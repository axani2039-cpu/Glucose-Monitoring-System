/*
 * RTC_PROGRAM.c
 *
 *  Created on: Aug 25, 2026
 *      Author: ahmed
 */

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/MCAL/TWI/TWI_INTERFACE.h"

#include "../INCLUDE/HAL/RTC/RTC_INTERFACE.h"
#include "../INCLUDE/HAL/RTC/RTC_PRIVATE.h"
#include "../INCLUDE/HAL/RTC/RTC_CFG.h"


static u8 BCD_to_DEC(u8 A_u8BCDValue)
{
    return ((A_u8BCDValue >> 4) * 10) + (A_u8BCDValue & 0x0F);
}

static u8 DEC_to_BCD(u8 A_u8DECValue)
{
    return ((A_u8DECValue / 10) << 4) | (A_u8DECValue % 10);
}

void HRTC_voidInit(void)
{

    MTWI_voidInit();
}

void HRTC_voidSetTime(RTC_Time_t *A_PtrTime)
{
    MTWI_voidSendStartCondition();
    MTWI_voidSendSlaveAddressWithWrite(RTC_SLAVE_ADDRESS);

    MTWI_voidSendDataByte(0x00);


    MTWI_voidSendDataByte(DEC_to_BCD(A_PtrTime->Seconds));
    MTWI_voidSendDataByte(DEC_to_BCD(A_PtrTime->Minutes));
    MTWI_voidSendDataByte(DEC_to_BCD(A_PtrTime->Hours));

    MTWI_voidSendStopCondition();
}

void HRTC_voidGetTime(RTC_Time_t *A_PtrTime)
{
    MTWI_voidSendStartCondition();
    MTWI_voidSendSlaveAddressWithWrite(RTC_SLAVE_ADDRESS);
    MTWI_voidSendDataByte(0x00);

    MTWI_voidSendRepeatedStart();
    MTWI_voidSendSlaveAddressWithRead(RTC_SLAVE_ADDRESS);

    A_PtrTime->Seconds = BCD_to_DEC(MTWI_u8ReceiveDataByte());

    MTWI_voidSendRepeatedStart();
    MTWI_voidSendSlaveAddressWithRead(RTC_SLAVE_ADDRESS);
    A_PtrTime->Minutes = BCD_to_DEC(MTWI_u8ReceiveDataByte());

    MTWI_voidSendRepeatedStart();
    MTWI_voidSendSlaveAddressWithRead(RTC_SLAVE_ADDRESS);
    A_PtrTime->Hours   = BCD_to_DEC(MTWI_u8ReceiveDataByte());

    MTWI_voidSendStopCondition();
}
