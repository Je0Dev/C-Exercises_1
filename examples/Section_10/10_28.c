#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	char str1[100], str2[100];
	int k;

	printf("Enter first text: ");
	read_text(str1, sizeof(str1), 1);

	printf("Enter second text: ");
	read_text(str2, sizeof(str2), 1);

	k = strcmp(str1, str2);
	/* We could omit the declaration of k and write: if(strcmp(str1, str2) == 0) */
	if(k == 0)
		printf("Same texts\n");
	else
	{
		printf("Different texts\n");
		if(strncmp(str1, str2, 3) == 0)
			printf("But the first 3 chars are the same\n");
	}
	return 0;
}
