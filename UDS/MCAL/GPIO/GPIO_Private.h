/***************************************************************************************************/
/*                                       GPIO_Private.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: Defining Registers
 ***************************************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
#include "../../LIB/std_types.h"


#define PORTA      *((volatile uint8 *) 0x3B)
#define DDRA	   *((volatile uint8 *) 0x3A)          /*Registers in PORTA IN MCU*/
#define PINA	   *((volatile uint8 *) 0x39)

#define PORTB      *((volatile uint8 *) 0x38)
#define DDRB	   *((volatile uint8 *) 0x37)		/*Registers in PORTB IN MCU*/
#define PINB       *((volatile uint8 *) 0x36)

#define PORTC       *((volatile uint8 *) 0x35)
#define DDRC		*((volatile uint8 *) 0x34)		/*Registers in PORTC IN MCU*/
#define PINC		*((volatile uint8 *) 0x33)

#define PORTD       *((volatile uint8 *) 0x32)
#define DDRD		*((volatile uint8 *) 0x31)		/*Registers in PORTD IN MCU*/
#define PIND		*((volatile uint8 *) 0x30)
#endif /* GPIO_PRIVATE_H_ */
