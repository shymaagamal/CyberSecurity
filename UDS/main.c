/*
 * main.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Shaimaa Gamal
 */


#include <stdio.h>
#include "HAL/LCD/lcd.h"
#include "HAL/LED/LED.h"
#include "HAL/UDS/uds.h"



uint8 access[2] = {0};
uint8 sfid[2] = {0};
uint8 g_seed[8] = {0};
uint8 g_encrypted_seed[8] = {0};
uint8 Secure_Access;
uint8 g_key[4] = {0};
int main(void)
{

		LED_setUpDirection(PORTA_ID, 7, PIN_OUTPUT);
		LCD_init();
		LCD_goToRowColumn(0, 1);
		USART_init();

	while(1)
	{
		//RECIVE ServiceID--->27  OR 31
		recieve_SID(access);


		if(access[0] == '2' && access[1] == '7')
		{
			Secure_Access=security_access_request(sfid,g_seed,g_encrypted_seed);

		}
		else if(access[0] == '3' && access[1] == '1')
		{
			if(Secure_Access == 1)
			{
				//receive 01
				recieve_SID(sfid);
				send_key(g_key,4);
				if(g_key[0] == 'A' && g_key[1] == 'A' && g_key[2] == '0' && g_key[3] == '0')
				{
					LED_ON(PORTA_ID, 7); // high for led
					LCD_goToRowColumn(0, 0);
					LCD_displayString("Congratulation");
					Positive_Response(SR_SID_1, SR_SID_2, SR_SSID_1, SR_SSID_2, 1, g_key);
				}
				else{

				}
			}
			else
			{
				recieve_SID(access);
				send_key(g_key, 4);
				send_wrong_Frame(31);
			}
		}




	}
}



