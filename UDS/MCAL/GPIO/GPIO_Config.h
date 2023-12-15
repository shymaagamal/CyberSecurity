/***************************************************************************************************/
/*                                       GPIO_Config.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: Defining
 ***************************************************************************************************/

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_
#include "../../LIB/std_types.h"
#include "../../LIB/BIT_Math.h"
#include "GPIO_Private.h"

#define PORTA_ID  0


#define PORTB_ID  1


#define PORTC_ID  2


#define PORTD_ID  3


#define LOGIC_LOW 0
#define LOGIC_HIGH  1

#define NUM_OF_PORTS 4
#define NUM_OF_PINS 8

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirection;


typedef enum
{
	Port_INPUT,port_OUTPUT
}GPIO_PortDirection;


void GPIO_SetupPin_Direction(uint8 port_id,uint8 pin_num,GPIO_PinDirection direction);
void GPIO_SetupPort_Direction(uint8 port_id,GPIO_PortDirection direction);

void GPIO_SetupPin_Value(uint8 port_id,uint8 bit_num,uint8 pin_value);
void GPIO_SetupPort_Value(uint8 port_id,uint8 port_value);

uint8 GPIO_GetPort_Value(uint8 port_id);
uint8 GPIO_GetPin_Value(uint8 port_id,uint8 pin_num);
void GPIO_TogglePin_Value(uint8 port_id,uint8 pin_num);

#endif /* GPIO_CONFIG_H_ */
