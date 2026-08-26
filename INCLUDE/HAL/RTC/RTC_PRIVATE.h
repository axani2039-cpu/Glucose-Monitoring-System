
/*
 * RTC_PRIVATE.h
 *
 *  Created on: Aug 25, 2026
 *      Author: ahmed
 */

#ifndef INCLUDE_HAL_RTC_RTC_PRIVATE_H_
#define INCLUDE_HAL_RTC_RTC_PRIVATE_H_


#define RTC_SLAVE_ADDRESS  0x68

static u8 BCD_to_DEC(u8 A_u8BCDValue);
static u8 DEC_to_BCD(u8 A_u8DECValue);


#endif /* INCLUDE_HAL_RTC_RTC_PRIVATE_H_ */
