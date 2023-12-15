/*
 * USART_program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_UART_USART_PROGRAM_C_
#define MCAL_UART_USART_PROGRAM_C_

#include "../../LIB/std_types.h"
#include "../../LIB/BIT_Math.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_registers.h"
#include "USART_config.h"

void USART_UCSRC_config(void)
{
	uint8 init_UCPOL, init_UCSZ0, init_UCSZ1, init_USBS, init_UPM0, init_UPM1, init_UMSEL;
	init_UCPOL  = UCPOL;
	init_UCSZ0  = (UCSZ & 1);
	init_UCSZ1  = (UCSZ >> 1) & 1;
	init_USBS   = USBS;
	init_UPM0   = (UPM & 1);
	init_UPM1   = (UPM >> 1);
	init_UMSEL  = 0;

	UCSRC_REG = (1 << UCSRC_URSEL) | (init_UMSEL << UCSRC_UMSEL)
			| (init_UPM1 << UCSRC_UPM1) | (init_UPM0 << UCSRC_UPM0) | (init_USBS << UCSRC_USBS)
			| (init_UCSZ1 << UCSRC_UCSZ1) | (init_UCSZ0 << UCSRC_UCSZ0) | (UCPOL << UCSRC_UCPOL) ;

}
void USART_init(void)
{
// baud rate (ubrrl  ubrrh(bit 7 = 0))
	UBRRL_REG = (uint8) USART_BAUD_RATE;
	UBRRH_REG = (uint8) (USART_BAUD_RATE >> 8);


	USART_UCSRC_config();

// frame format (ucsrc (bit 7 = 1))
	UCSRA_REG->U2X =0;

	// enable tx rx
	UCSRB_REG->TXEN = 1;
	UCSRB_REG->RXEN = 1;

}

void USART_TX_polling(uint8 Data)
{
	while(UCSRA_REG->UDRE != 1);
	UDR_REG = Data;
	while(UCSRA_REG->TXC  != 1);

}
void USART_TX(uint8 Data)
{
	if(UCSRA_REG->UDRE != 1)
	{

	}
	UDR_REG = Data;
	if(UCSRA_REG->TXC  != 1)
	{

	}

}

uint8 USART_RX_polling(void)
{
	while(UCSRA_REG->RXC != 1);
	return UDR_REG;
}
uint8 USART_RX(void)
{
	if(UCSRA_REG->RXC != 1)
	{

	}
	return UDR_REG;
}

void USART_sendingString(uint8 *str)
{
	uint8 i=0;
	for(i =0; str[i] !='\0';i++)
	{
		USART_TX_polling(str[i]);
	}
}

void USART_receiveString(uint8 * str)
{
	uint8 i=0;
	str[i]=USART_RX();
	for(;str[i] !='\0';)
	{
		i++;
		str[i]=USART_RX_polling();

	}
	str[i]=0;
}
#endif /* MCAL_UART_USART_PROGRAM_C_ */
