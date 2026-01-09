#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	char ch, max_ch, str[100];
	int i, len, max_times, low_let[26] = {0}; /* The size of the array is equal to the number of the lowercase letters. This array holds the number of the appearances of each letter. For example, low_let[0] holds the appearances of 'a', and low_let[25] the appearances of 'z'. */
	int dig[10] = {0}; /* Similarly, dig[0] holds the appearances of digit 0, and dig[9] the appearances of digit 9. */

	printf("Enter text: ");
	len = read_text(str, sizeof(str), 1);
	max_ch = max_times = 0;
	for(i = 0; i < len; i++) 
	{
		if((str[i] >= 'a') && (str[i] <= 'z'))
		{
			ch = str[i]-'a';
			low_let[ch]++; /* For example, if the character is 'a', the value of low_let['a'-'a'] = low_let[0], which holds the appearances of 'a', will be incremented by one. */
			if(low_let[ch] > max_times)
			{
				max_times = low_let[ch];
				max_ch = str[i];
			}
		}
		else if((str[i] >= '0') && (str[i] <= '9'))
			dig[str[i]-'0']++; 
	}
	printf("***** Lowercase letters appearances\n"); 
	for(i = 0; i < 26; i++)
		if(low_let[i] != 0) /* Check if the letter appears once at least. */
			printf("Letter %c appeared %d times\n", 'a'+i, low_let[i]);

	printf("***** Digits appearances\n"); 
	for(i = 0; i < 10; i++)
		if(dig[i] != 0)
			printf("Digit %d appeared %d times\n", i, dig[i]);
	if(max_times != 0)
		printf("'%c' appears %d times\n", max_ch, max_times);
	return 0;
}
