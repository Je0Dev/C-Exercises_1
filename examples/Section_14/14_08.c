#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int read_text(char str[], int size, int flag);

int main(void)
{
	char *ptr[SIZE], str[100];
	int i, pos, len, max_len; /* pos is used to indicate the ptr element, which points to the longest string. max_len holds its length. */
	pos = max_len = 0; 
	for(i = 0; i < SIZE; i++)
	{
		printf("Enter text: ");
		len = read_text(str, sizeof(str), 1);
		/* Allocate the required memory. */ 
		ptr[i] = (char*) malloc(len+1);
		if(ptr[i] == NULL)
		{
			printf("Error: Not available memory\n");
			exit(EXIT_FAILURE);
		}
		/* Store the string in the allocated memory. */
		strcpy(ptr[i], str);
		/* We compare the length of each string against max_len and if a longer string is found, we store its position and length. */
		if(len > max_len)
		{
			pos = i;
			max_len = len;
		}
	}
	printf("Longer string: %s\n", ptr[pos]);
	for(i = 0; i < SIZE; i++)
		free(ptr[i]);
	return 0;
}
