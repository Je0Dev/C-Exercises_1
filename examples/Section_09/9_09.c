#include <stdio.h>
int main(void)
{
	char chk_dig;
	int i, ch, sum, temp;

	sum = 0;	
	printf("Enter IMEI (15 digits): ");
	for(i = 1; i < 15; i++) /* Read the first 14 IMEI's digits.*/
	{
		ch = getchar();
		if((i & 1) == 1) /* Check if the digit's position is odd. */
			sum += ch-'0'; /* To find the numeric value of that digit, the ASCII value of 0 is subtracted. */
		else 
		{
			temp = 2*(ch-'0');
			if(temp >= 10)
				temp = (temp/10) + (temp%10); /* If the digit's doubling produces a two-digit number we calculate the sum of these digits. */
			sum += temp;
		}	
	}
	ch = getchar(); /* Read the IMEI's last digit, that is, the Luhn digit. */
	ch = ch-'0'; 

	chk_dig = sum%10;
	if(chk_dig != 0)
		chk_dig = 10-chk_dig;

	if(ch == chk_dig)
		printf("*** Valid IMEI ***\n");
	else
		printf("*** Invalid IMEI ***\n");
	return 0;
}
