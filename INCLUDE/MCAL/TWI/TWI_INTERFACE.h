/*
 * TWI_INTERFACE.h
 *
 *  Created on: Aug 25, 2026
 *      Author: ahmed
 */

#ifndef INCLUDE_MCAL_TWI_TWI_INTERFACE_H_
#define INCLUDE_MCAL_TWI_TWI_INTERFACE_H_


void MTWI_voidInit(void);
void MTWI_voidSendStartCondition(void);
void MTWI_voidSendRepeatedStart(void);
void MTWI_voidSendSlaveAddressWithWrite(u8 A_u8SlaveAddress);
void MTWI_voidSendSlaveAddressWithRead(u8 A_u8SlaveAddress);
void MTWI_voidSendDataByte(u8 A_u8DataByte);
u8   MTWI_u8ReceiveDataByte(void);
void MTWI_voidSendStopCondition(void);


#endif /* INCLUDE_MCAL_TWI_TWI_INTERFACE_H_ */
