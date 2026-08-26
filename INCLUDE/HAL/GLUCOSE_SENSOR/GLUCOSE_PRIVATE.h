/*
 * GLUCOSE_PRIVATE.h
 *
 *  Created on: Aug 26, 2026
 *      Author: lenovo
 */


#ifndef INCLUDE_HAL_GLUCOSE_SENSOR_GLUCOSE_PRIVATE_H_
#define INCLUDE_HAL_GLUCOSE_SENSOR_GLUCOSE_PRIVATE_H_


#define GLUCOSE_SENSOR_MAP(ADC_VALUE)                                      \
(                                                                         \
    GLUCOSE_MIN_VALUE +                                                   \
    (((ADC_VALUE) * (GLUCOSE_MAX_VALUE - GLUCOSE_MIN_VALUE))              \
    / (ADC_MAX_VALUE - ADC_MIN_VALUE))                                    \
)



#endif /* INCLUDE_HAL_GLUCOSE_SENSOR_GLUCOSE_PRIVATE_H_ */
