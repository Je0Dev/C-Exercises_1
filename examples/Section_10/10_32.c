#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	char str[100];
	int i, len, cnt;

	printf("Original text: ");
	len = read_text(str, sizeof(str), 1);

	printf("Compressed text: ");
	i = 0;
	while(i < len)
	{
		cnt = 1;
		if(str[i] < '0' || str[i] > '9') /* Digits are not compressed. */
		{
			while(str[i+cnt] == str[i]) /* Check if the current character, that is str[i], is repeated in the next places. */
				cnt++;

			if(cnt == 1)
				printf("%c", str[i]);
			else
				printf("%d%c", cnt, str[i]);
		}
		else
			printf("%c", str[i]);

		i += cnt;
	}
	return 0;
}
