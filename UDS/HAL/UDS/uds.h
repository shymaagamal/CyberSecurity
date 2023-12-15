/*
 * uds.h
 *
 *  Created on: Dec 15, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef HAL_UDS_H_
#define HAL_UDS_H_

#define NEGATIVE_RESPONSE_ID_1    '7'
#define NEGATIVE_RESPONSE_ID_2    'F'

#define NRC_WRONG_KEY_1           '3'
#define NRC_WRONG_KEY_2           '5'

#define NRC_NO_ACCESS             '3'

//uart sent Security access service id
#define SA_SID_1                  '2'
#define SA_SID_2                  '7'

//uart sent Security access sub service id for generate seed
#define SA_SEED_1                 '0'
#define SA_SEED_2                 '1'

//uart sent Security access sub service id for send key
#define SA_KEY_1                  '0'
#define SA_KEY_2                  '2'

#define SR_SID_1                  '3'
#define SR_SID_2                  '1'

#define SR_SSID_1                  '0'
#define SR_SSID_2                  '1'


void recieve_SID(uint8 *access);
uint8 security_access_request(uint8 *sfid,uint8 *g_seed,uint8 *g_encrypted_seed);
void send_wrong_Frame(uint8 SID);
void Positive_Response(uint8 First_digit_SID, uint8 Second_digit_SID, uint8 First_digit_SSID, uint8 Second_digit_SSID,uint8 flag ,uint8 *routine);
uint8 verify_key(uint8 *key, uint8 *my_key);
void send_key(uint8 *ptr_data, uint8 size);
void generate_seed(uint8 *seed_ptr, uint8 *encrypted_ptr);
void request_for_key(uint8 *sfid,uint8 *g_seed,uint8 *g_encrypted_seed);
#endif /* HAL_UDS_H_ */
