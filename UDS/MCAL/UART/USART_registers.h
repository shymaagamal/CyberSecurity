/*
 * USART_registers.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_UART_USART_REGISTERS_H_
#define MCAL_UART_USART_REGISTERS_H_

#include "../../LIB/std_types.h"
/************************************************************************************************************
 *									UDR Register
 ************************************************************************************************************/
#define UDR_REG     *((volatile uint8 *) 0x2c)

/************************************************************************************************************
 *									UCSRA Register
 ************************************************************************************************************/

typedef struct
{
	uint8 MPCM:1;
	uint8 U2X:1;
	uint8 PE:1;
	uint8 DOR:1;
	uint8 FE:1;
	uint8 UDRE:1;
	uint8 TXC:1;
	uint8 RXC:1;
}UCSRA;

#define UCSRA_REG		((volatile UCSRA *) 0x2B)
/************************************************************************************************************
 *									UCSRB Register
 ************************************************************************************************************/

typedef struct
{
	uint8 TXB8:1;
	uint8 RXB8:1;
	uint8 UCSZ2:1;
	uint8 TXEN:1;
	uint8 RXEN:1;
	uint8 UDRIE:1;
	uint8 TXCIE:1;
	uint8 RXCIE:1;
}UCSRB;

#define UCSRB_REG		((volatile UCSRB *) 0x2A)
/************************************************************************************************************
 *									UCSRC Register
 ************************************************************************************************************/
#define UCSRC_REG     *((volatile uint8 *) 0x40)

#define UCSRC_URSEL	  7
#define UCSRC_UMSEL   6
#define UCSRC_UPM1	  5
#define UCSRC_UPM0	  4
#define UCSRC_USBS    3
#define UCSRC_UCSZ1   2
#define UCSRC_UCSZ0   1
#define UCSRC_UCPOL   0
/************************************************************************************************************
 *									UBRRH Register
 ************************************************************************************************************/
#define UBRRH_REG     *((volatile uint8 *) 0x40)
#define UBRRL_REG     *((volatile uint8 *) 0X29)
#endif /* MCAL_UART_USART_REGISTERS_H_ */
