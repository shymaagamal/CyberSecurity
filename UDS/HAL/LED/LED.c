/*
 * Application.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */

#include "LED.h"

void LED_setUpDirection(uint8 port_id,uint8 pin_num,GPIO_PinDirection direction)
{
	GPIO_SetupPin_Direction(port_id,pin_num, direction);


}

void LED_ON(uint8 port_id,uint8 pin_num)
{
	GPIO_SetupPin_Value(port_id,pin_num,LOGIC_HIGH);
}
void LED_OFF(uint8 port_id,uint8 pin_num)
{
	GPIO_SetupPin_Value(port_id,pin_num,LOGIC_LOW);
}

void LED_Toggle(uint8 port_id, uint8 pin_num)
{
	GPIO_TogglePin_Value(port_id, pin_num);
}
