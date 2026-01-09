#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);
int main(void)
{
	char *ptr, str[100];
	int cnt;

	printf("Enter text: ");
	read_text(str, sizeof(str), 1);

	cnt = 0;
	ptr = str;
	while(*ptr != '\0')
	{
		if(*ptr == ' ')
			*ptr = '\n';
		else if(*ptr == 'a')
			*ptr = 'p';
		else if(*ptr == 'b')
			cnt++;
		ptr++;
	}
	printf("Len = %d Times = %d\nText = %s\n", ptr-str, cnt, str); 
	return 0;
}
