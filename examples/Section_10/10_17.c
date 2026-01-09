#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	char str[100], new_str[200]; /* The new string will be stored into new_str. It is declared with double size, just for the case that the input string contains only '*'. */
	int i, j, len, small_let, big_let;

	while(1) 
	{
		printf("Enter text: ");
		len = read_text(str, sizeof(str), 1);

		if(str[0] == 'e' && str[1] == 'n' && str[2] == 'd')
			break;

		j = small_let = big_let = 0;
		for(i = 0; i < len; i++)
		{
			if(str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32; /* The difference of an uppercase letter with the respective lowercase is 32, according to the ASCII code. */
				big_let++;
			}
			else if(str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
				small_let++;
			}
			new_str[j] = str[i]; /* Copy each character of the input string in the position indicated by j. */
			if(str[i] == '*') 
			{
				j++; /* Increase j to store another '*'. */
				new_str[j] = '*';
			}
			j++; /* Increase j to store the next character. */
		}
		new_str[j] = '\0';
		printf("%s contains %d lowercase and %d uppercase letters\n", new_str, small_let, big_let);
	}
	return 0;
}
