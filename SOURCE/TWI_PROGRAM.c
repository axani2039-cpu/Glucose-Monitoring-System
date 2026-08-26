/*
 * TWI_PROGRAM.c
 *
 *  Created on: Aug 25, 2026
 *      Author: ahmed
 */


#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/MCAL/TWI/TWI_INTERFACE.h"
#include "../INCLUDE/MCAL/TWI/TWI_PRIVATE.h"
#include "../INCLUDE/MCAL/TWI/TWI_CFG.h"

void MTWI_voidInit(void)
{

    TWBR = (u8) (((F_CPU / SCL_CLOCK) - 16) / 2);

    TWSR = 0x00;

    SET_BIT(TWCR, TWEN);
}

void MTWI_voidSendStartCondition(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) == 0);
}

void MTWI_voidSendRepeatedStart(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) == 0);
}

void MTWI_voidSendSlaveAddressWithWrite(u8 A_u8SlaveAddress)
{
    TWDR = (A_u8SlaveAddress << 1);
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) == 0);
}

void MTWI_voidSendSlaveAddressWithRead(u8 A_u8SlaveAddress)
{
    TWDR = (A_u8SlaveAddress << 1) | 0x01;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) == 0);
}

void MTWI_voidSendDataByte(u8 A_u8DataByte)
{
    TWDR = A_u8DataByte;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) == 0);
}

u8 MTWI_u8ReceiveDataByte(void)
{

    TWCR = (1 << TWINT) | (1 << TWEN);
    while (GET_BIT(TWCR, TWINT) == 0);
    return TWDR;
}

void MTWI_voidSendStopCondition(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}
