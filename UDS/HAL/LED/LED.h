
/***************************************************************************************************/
/*                                       Application.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: some projects using GPIO Driver
 ***************************************************************************************************/

#ifndef APPLICATION_H_
#define APPLICATION_H_


#define DISPLAY_ON_SEG1 1

#include "../../MCAL/GPIO/GPIO_Config.h"
#include <util/delay.h>


#define LED_RED_PIN      7
#define LED_GREEN_PIN    4
#define LED_BLUE_PIN     5
#define LED_YELLOW_PIN   6

void LED_setUpDirection(uint8 port_id,uint8 pin_num,GPIO_PinDirection direction);
void LED_ON(uint8 port_id,uint8 pin_num);
void LED_OFF(uint8 port_id,uint8 pin_num);
void LED_Toggle(uint8 port_id,uint8 pin_num);

#endif /* APPLICATION_H_ */
