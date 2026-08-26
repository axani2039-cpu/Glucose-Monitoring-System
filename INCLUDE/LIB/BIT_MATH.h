/*
 * BIT_MATH.h
 *
 *  Created on: Aug 26, 2026
 *      Author: lenovo
 */

#ifndef INCLUDE_LIB_BIT_MATH_H_
#define INCLUDE_LIB_BIT_MATH_H_


/* Bit Manipulation Macros */
#define SET_BIT(Reg, bitnum)         ((Reg) |= (1 << (bitnum)))
#define GET_BIT(Reg, bitnum)         (((Reg) >> (bitnum)) & 0x01)
#define CLR_BIT(Reg, bitnum)         ((Reg) &= ~(1 << (bitnum)))
#define TOGGLE_BIT(Reg, bitnum)      ((Reg) ^= (1 << (bitnum)))
#define READ_BIT(REG, BIT)    (((REG) >> (BIT)) & 1)

/* Byte Assignment Macro */
#define SET_BYTE(Reg, value)         ((Reg) = (value))

/* Bit Concatenation Macros (For Pre-Compile Configuration) */
#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0)     CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif /* INCLUDE_LIB_BIT_MATH_H_ */
