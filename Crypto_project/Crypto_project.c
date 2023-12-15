/*
 * MAIN.C
 *
 *  Created on: Dec 13, 2023
 *      Author: Shaimaa Gamal
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main ()
{
	char status;
	int key=0;
	char message[100];
	int c;

	printf ("If you want to encrypt Enter e else enter d\n");
	while(1)
	{
		scanf ("%c", &status);
		if(status == 'e' || status == 'E' ||status == 'd'||status == 'D')
		{
			break;
		}
		printf ("Enter valid Status\n");
	}


	printf("Enter your message\n");
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(message, sizeof(message), stdin);



	printf ("Enter Key : \n");
	scanf ("%d", &key);
	while(key <0 || key >255)
	{
		printf ("Enter valid Key  from 0 to 255 : \n");
		scanf ("%d", &key);
	}


	if(status=='e'||status=='E')
	{
		for (int i = 0; i < strlen(message); i++) {
			if (message[i] >= 'A' && message[i] <= 'Z') {
				message[i] = (message[i] - 'A' + key) % 26 + 'A';
			} else if (message[i] >= 'a' && message[i] <= 'z') {
				message[i] = (message[i] - 'a' + key) % 26 + 'a';
			}
		}

	}
	else if(status=='d'||status=='D')
	{
		for (int i = 0; i < strlen(message); i++) {
			if (message[i] >= 'A' && message[i] <= 'Z') {
				message[i] = (message[i] - 'A' + 26-key) % 26 + 'A';
			} else if (message[i] >= 'a' && message[i] <= 'z') {
				message[i] = (message[i] - 'a' +26- key) % 26 + 'a';
			}
		}
	}

	printf ("%s",message);

	system("pause");
	return 0;
}
