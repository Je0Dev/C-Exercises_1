#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	char str[100];
	int i, len;

	printf("Enter text: ");
	len = read_text(str, sizeof(str), 1);

	for(i = 0; i < len; i++)
	{
		if(str[i] == 'a')
			str[i] = ' ';
		else 
			break;
	}
	for(i = len-1; i >= 0; i--)
	{
		if(str[i] == 'a')
			str[i] = ' ';
		else 
			break;
	}
	printf("Text: %s\n", str);
	return 0;
}
