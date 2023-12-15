/*
 * USART_config.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_UART_USART_CONFIG_H_
#define MCAL_UART_USART_CONFIG_H_


#define UCPOL					0/*put 0 for rising edge ,, put 1 for falling edge*/

/*put 0 for 5-bit
 *put 1 for 6-bit
 *put 2 for 7-bit
 *put 3  for 8-bit
 *put 7	for 9-bit
 *  */
#define UCSZ  3
/*put 0 for one stop bit
 * put 1 for two stop bit
 * */
#define USBS 	0
/*put 0 to disable parity mmod
 * put 2 to enable even parity
 * put 3 to odd parity*/
#define UPM   0
/*PUT 0 FOR Async
 * put 1 for Sync
 */
#define UMSEL   0
/*to select UBRRH put 0
 *PUT 1to select USCRC
 * */
#define URSEL  1


#define USART_BAUD_RATE 103 // 9600 bps at 16MHz sys clock




#endif /* MCAL_UART_USART_CONFIG_H_ */
