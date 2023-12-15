/***************************************************************************************************/
/*                                       GPIO_Interface.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: Defining bit math
 ***************************************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM)                         (REG|=(1<<BIT_NUM))

#define CLEAR_BIT(REG,BIT_NUM)                       (REG &= ~(1<<BIT_NUM))

#define TOGGLE_BIT(REG,BIT_NUM)                      (REG ^= (1<<BIT_NUM))


#define GET_BIT(REG,BIT_NUM)                         ((REG >> BIT_NUM) & 0x01)/*(REG& (1<<BIT_NUM)>> BIT_NUM)*/


#define SET_BYTE(REG,VAL)                            REG=VAL
#define CLEAR_BYTE(REG) 							 REG=0x00

#define  MASK(REG,MASKED)                            REG=&MASKED

#define CONC_BYTE(B0,B1,B2,B3,B4,B5,B6,B7)           0b##B0##B1##B2##B3##B4##B5##B6##B7




#endif /* GPIO_INTERFACE_H_ */
