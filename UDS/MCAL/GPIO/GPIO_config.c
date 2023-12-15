/***************************************************************************************************/
/*                                       GPIO_Program.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: Defining of Functions
 ***************************************************************************************************/


#include "GPIO_Config.h"
#include "GPIO_Private.h"


void GPIO_SetupPin_Direction(uint8 port_id,uint8 pin_num,GPIO_PinDirection direction)
{
	if(pin_num > NUM_OF_PINS || port_id > NUM_OF_PORTS)
	{

	}
	else
	{


		switch(port_id)
		{
			case PORTA_ID:
				if(direction==PIN_INPUT)
				{

					CLEAR_BIT(DDRA,pin_num);
				}
				else if(direction==PIN_OUTPUT)
				{
					SET_BIT(DDRA,pin_num);
				}
				break;
			case PORTB_ID:
				if(direction==PIN_INPUT)
				{
					CLEAR_BIT(DDRB,pin_num);
				}
				else if(direction==PIN_OUTPUT)
				{
					SET_BIT(DDRB,pin_num);
				}
				break;
			case PORTC_ID:
				if(direction==PIN_INPUT)
				{
					CLEAR_BIT(DDRC,pin_num);
				}
				else if(direction==PIN_OUTPUT)
				{
					SET_BIT(DDRC,pin_num);
				}
				break;
			case PORTD_ID:
				if(direction==PIN_INPUT)
				{
					CLEAR_BIT(DDRD,pin_num);
				}
				else if(direction==PIN_OUTPUT)
				{
					SET_BIT(DDRD,pin_num);
				}
				break;

			}
	}
}
void GPIO_SetupPort_Direction(uint8 port_id,GPIO_PortDirection direction)
{
	if(port_id > NUM_OF_PORTS)
	{

	}
	else
	{
		switch(port_id)
			{
			case PORTA_ID:
				if(direction==Port_INPUT)
				{

					CLEAR_BYTE(DDRA);
				}
				else if(direction==port_OUTPUT)
				{
					SET_BYTE(DDRA,0xFF);
				}
				break;
			case PORTB_ID:
				if(direction==Port_INPUT)
				{

					CLEAR_BYTE(DDRB);
				}
				else if(direction==port_OUTPUT)
				{
					SET_BYTE(DDRB,0xFF);
				}
				break;
			case PORTC_ID:
				if(direction==Port_INPUT)
				{

					CLEAR_BYTE(DDRC);
				}
				else if(direction==port_OUTPUT)
				{
					SET_BYTE(DDRC,0xFF);
				}
				break;
			case PORTD_ID:
				if(direction==Port_INPUT)
				{

					CLEAR_BYTE(DDRD);
				}
				else if(direction==port_OUTPUT)
				{
					SET_BYTE(DDRD,0xFF);
				}
				break;

			}
	}
}

void GPIO_SetupPin_Value(uint8 port_id,uint8 pin_num,uint8 pin_value)
{

		switch(port_id)
			{
			case PORTA_ID:
				if(pin_value ==LOGIC_LOW)
				{
					CLEAR_BIT(PORTA,pin_num);
				}
				else if(pin_value == LOGIC_HIGH)
				{
					SET_BIT(PORTA,pin_num);
				}

				break;
			case PORTB_ID:
				if(pin_value ==LOGIC_LOW)
				{
					CLEAR_BIT(PORTB,pin_num);
				}
				else if(pin_value == LOGIC_HIGH)
				{
					SET_BIT(PORTB,pin_num);
				}
				break;
			case PORTC_ID:
				if(pin_value ==LOGIC_LOW)
				{
					CLEAR_BIT(PORTC,pin_num);
				}
				else if(pin_value == LOGIC_HIGH)
				{
					SET_BIT(PORTC,pin_num);
				}
				break;
			case PORTD_ID:
				if(pin_value ==LOGIC_LOW)
				{
					CLEAR_BIT(PORTD,pin_num);
				}
				else if(pin_value == LOGIC_HIGH)
				{
					SET_BIT(PORTD,pin_num);
				}
				break;

			}

}
void GPIO_SetupPort_Value(uint8 port_id,uint8 port_value)
{
	if( port_id > NUM_OF_PORTS)
	{

	}
	else
	{


		switch(port_id)
			{
			case PORTA_ID:
				PORTA=port_value;

				break;
			case PORTB_ID:
				PORTB=port_value;
				break;
			case PORTC_ID:
				PORTC=port_value;
				break;
			case PORTD_ID:
				PORTD=port_value;
				break;

			}
	}
}
uint8 GPIO_GetPin_Value(uint8 port_id,uint8 pin_num)
{
	uint8 valu=0;
	if(pin_num > NUM_OF_PINS || port_id > NUM_OF_PORTS)
	{

	}
   else
	{

	switch(port_id)
		{
		case PORTA_ID:
			valu=GET_BIT(PINA,pin_num);

			break;
		case PORTB_ID:
			valu= GET_BIT(PINB,pin_num);
			break;
		case PORTC_ID:
			valu= GET_BIT(PINC,pin_num);
			break;
		case PORTD_ID:
			valu= GET_BIT(PIND,pin_num);
			break;

		}

}
	return valu;
}
uint8 GPIO_GetPort_Value(uint8 port_id)
{
	uint8 pin=0x00;
	if( port_id > NUM_OF_PORTS)
	{

	}
	else
	{

		switch(port_id)
			{
			case PORTA_ID:
				pin= PINA;
				break;
			case PORTB_ID:
				pin= PINB;
				break;
			case PORTC_ID:
				pin= PINC;
				break;
			case PORTD_ID:
				pin= PIND;
				break;
			}
	}
	return pin;
}
void GPIO_TogglePin_Value(uint8 port_id,uint8 pin_num)
{
	if(pin_num > NUM_OF_PINS || port_id > NUM_OF_PORTS)
	{

	}
	else
	{
		switch(port_id)
		{
			case PORTA_ID:
				TOGGLE_BIT(PORTA,pin_num);
				break;

			case PORTB_ID:
				TOGGLE_BIT(PORTB,pin_num);
				break;

			case PORTC_ID:
				TOGGLE_BIT(PORTC,pin_num);
				break;

			case PORTD_ID:
				TOGGLE_BIT(PORTD,pin_num);
				break;

			}
	}

}
