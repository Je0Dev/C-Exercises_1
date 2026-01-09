#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	char upc[13];
	int i, len, flag, chk_dig, sum;

	while(1)
	{
		printf("Enter UPC (12 digits): ");
		len = read_text(upc, sizeof(upc), 1);
		if(len != 12)
		{
			printf("Error: wrong length\n");
			continue;
		}
		flag = 1;
		for(i = 0; i < 12; i++)
		{
			if(upc[i] < '0' || upc[i] > '9')
			{
				printf("Error: only digits allowed\n");
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	sum = 0;
	for(i = 0; i < 11; i+=2)
		sum += upc[i]-'0'; /* Subtract '0' to get the numeric value of the digit character. */
	sum *= 3;
	for(i = 1; i < 11; i+=2)
		sum += upc[i]-'0';

	chk_dig = 10-(sum%10);
	if(chk_dig == 10)
		chk_dig = 0;
	
	if(chk_dig == (upc[11]-'0'))
		printf("Valid barcode\n");
	else
		printf("Wrong check digit. The correct is %d\n", chk_dig);
	return 0;
}
