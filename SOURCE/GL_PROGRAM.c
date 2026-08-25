/*
 * GL_PROGRAM.c
 *
 *  Created on: Aug 25, 2026
 *      Author: ahmed
 */


#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

#include "../INCLUDE/MCAL/GL/GL_INTERFACE.h"
#include "../INCLUDE/MCAL/GL/GL_PRIVATE.h"

void MGI_voidEnable(void) {
    SET_BIT(SREG , GLOBAL_INTERRUPT_ENABLE_BIT);
}

void MGI_voidDisable(void) {
    CLEAR_BIT(SREG , GLOBAL_INTERRUPT_ENABLE_BIT);
}
