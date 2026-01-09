#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int read_text(char str[], int size, int flag);

int main(void)
{
	char *temp, *ptr[SIZE], str[SIZE][100];
	int i, j;

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter name: ");
		read_text(str[i], sizeof(str[i]), 1);
		ptr[i] = str[i]; /* The elements of the array point to the input strings. */
	}
	for(i = 0; i < SIZE-1; i++)
	{
		for(j = i+1; j < SIZE; j++)
		{
			/* If the string pointed to by ptr[j] is less than the string pointed to by ptr[i], swap the respective pointers. */
			if(strcmp(ptr[j], ptr[i]) < 0)
			{
				temp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = temp;
			}	 
		}
	}
	for(i = 0; i < SIZE; i++)
		printf("%s\n", ptr[i]);
	return 0;
}
