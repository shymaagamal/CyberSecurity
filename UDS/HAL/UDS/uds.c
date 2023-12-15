/*
 * uds.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Shaimaa Gamal
 */

#include "../../LIB/std_types.h"
#include "../../MCAL/UART/USART_registers.h"
#include "../../MCAL/UART/USART_interface.h"
#include "uds.h"


void recieve_SID(uint8 *access){
	access[0]=USART_RX_polling();
	access[1]=USART_RX_polling();
	USART_TX_polling(' ');

}
uint8 security_access_request(uint8 *sfid,uint8 *g_seed,uint8 *g_encrypted_seed)
{

	uint8 l_key[8] = {0};
	uint8 Secure_Access;
	//recieve sub service ID
	recieve_SID(sfid);
	if(sfid[0] == '0' && sfid[1] == '1')
	{
		request_for_key(sfid,g_seed,g_encrypted_seed);
		//wait for 27 SID again but with sub service ID = 02
		recieve_SID(sfid);
		if(sfid[0] == '2' && sfid[1] == '7')
		{
			recieve_SID(sfid);
			if(sfid[0] == '0' && sfid[1] == '2')
			{
				//now receive the encrypted seed
				send_key(l_key, 8);
				//check the data
				Secure_Access = verify_key(l_key, g_encrypted_seed);
				if(Secure_Access == 1)
				{
					//secure_access_positive_response();
					Positive_Response(SA_SID_1, SA_SID_2, SA_KEY_1, SA_KEY_2, 0, 0);
				}
				else{
					send_wrong_Frame(27);
				}

			}


		}
	}
	return Secure_Access;
}
void Positive_Response(uint8 First_digit_SID, uint8 Second_digit_SID, uint8 First_digit_SSID, uint8 Second_digit_SSID,uint8 flag ,uint8 *routine){

	USART_TX_polling(' ');
	// ackt for accept response
	USART_TX_polling(First_digit_SID + 4);
	USART_TX_polling(Second_digit_SID);
	USART_TX_polling(' ');
	USART_TX_polling(First_digit_SSID);
	USART_TX_polling(Second_digit_SSID);
	USART_TX_polling(' ');

	if(flag == 1){
		for(uint8 i = 0 ; i < 4 ; i++){
			USART_TX_polling(routine[i]);
		}
	}


}
void send_wrong_Frame(uint8 SID){
	//7f
	USART_TX_polling(' ');
	USART_TX_polling(NEGATIVE_RESPONSE_ID_1);
	USART_TX_polling(NEGATIVE_RESPONSE_ID_2);
	USART_TX_polling(' ');

	switch(SID){
	case 27: //27 35
		USART_TX_polling(SA_SID_1);
		USART_TX_polling(SA_SID_2);

		USART_TX_polling(' ');

		USART_TX_polling(NRC_WRONG_KEY_1);
		USART_TX_polling(NRC_WRONG_KEY_2);
		USART_TX_polling(' ');
		break;
	case 31: //31 33
		//31
		USART_TX_polling(SR_SID_1);
		USART_TX_polling(SR_SID_2);

		USART_TX_polling(' ');
		//33
		USART_TX_polling(NRC_NO_ACCESS);
		USART_TX_polling(NRC_NO_ACCESS);

		USART_TX_polling(' ');
		break;
	}
}

uint8 verify_key(uint8 *key, uint8 *my_key)
{

	//flag = 1 means keys is identical
	uint8 flag = 1;

	for(uint8 i = 0 ; i < 8 ; i++){
		if(key[i] != my_key[i]){

			//flag = 0 means keys is not the same
			flag = 0;
			return flag;

		}
	}

	return flag;
}
void send_key(uint8 *ptr_data, uint8 size){
	for(uint8 i = 0 ; i < size ; i++){
		ptr_data[i]=USART_RX_polling();
	}

	USART_TX_polling(' ');
}
void generate_seed(uint8 *seed_ptr, uint8 *encrypted_ptr){

	for(uint8 i = 0 ; i < 8 ; i++){
		// Generate a random digit between 0 and 7 and add 48 to convert it to ASCII
		seed_ptr[i] = rand()%8 + 48;
		// Encrypt the generated digit by adding 2
		encrypted_ptr[i] = seed_ptr[i] + 1;
	}

}

void request_for_key(uint8 *sfid,uint8 *g_seed,uint8 *g_encrypted_seed){

	generate_seed(g_seed, g_encrypted_seed);



	//send 27 + 40  (Postive Responce ID FOR security access id)
	USART_TX_polling('6');
	USART_TX_polling('7');

	USART_TX_polling(' ');

	//send 01
	USART_TX_polling(sfid[0]);
	USART_TX_polling(sfid[1]);

	//send the seed
	for(uint8 i = 0 ; i < 8 ; i++){

		if(i%2 == 0){
			USART_TX_polling(' ');
		}
		USART_TX_polling(g_seed[i]);
	}
	USART_TX_polling(' ');
}
