/*
 * USART_interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_UART_USART_INTERFACE_H_
#define MCAL_UART_USART_INTERFACE_H_

void USART_UCSRC_config(void);
void USART_init(void);
void USART_TX_polling(uint8 Data);
uint8 USART_RX_polling(void);
void USART_TX(uint8 Data);
uint8 USART_RX(void);

void USART_sendingString(uint8 *str);
void USART_receiveString(uint8 * str);

#endif /* MCAL_UART_USART_INTERFACE_H_ */
