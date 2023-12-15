 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Shaimaa G.Salem
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "../../MCAL/GPIO/GPIO_Config.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define LCD_PIN1    0
#define LCD_PIN2    1
#define LCD_PIN3    2
#define LCD_PIN4    3

#define LCD_RS_PIN  3
#define LCD_EN_PIN  2


#define CLEAR_COMMAND 0x01




//#define LCD_DATA_PORT PORTD
//#define LCD_DATA_PORT_DIR DDRC
void LCD_init(void);
void LCD_writeCommand(uint8 command);
void LCD_writeData(uint8 command);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_displayString(const char *Str);
void LCD_clearScreen(void);
void LCD_intgerToString(int data);
#endif /* LCD_H_ */
