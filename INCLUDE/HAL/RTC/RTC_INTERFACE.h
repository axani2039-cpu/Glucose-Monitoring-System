/*
 * RTC_INTERFACE.h
 *
 *  Created on: Aug 25, 2026
 *      Author: ahmed
 */

#ifndef INCLUDE_HAL_RTC_RTC_INTERFACE_H_
#define INCLUDE_HAL_RTC_RTC_INTERFACE_H_


typedef struct {
    u8 Seconds;
    u8 Minutes;
    u8 Hours;
} RTC_Time_t;

void HRTC_voidInit(void);
void HRTC_voidSetTime(RTC_Time_t *A_PtrTime);
void HRTC_voidGetTime(RTC_Time_t *A_PtrTime);


#endif /* INCLUDE_HAL_RTC_RTC_INTERFACE_H_ */
