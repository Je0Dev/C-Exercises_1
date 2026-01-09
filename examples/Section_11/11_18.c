#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *max_str(char str1[], char str2[]); 
int read_text(char str[], int size, int flag);

int main(void)
{
	char *ptr, str1[100], str2[100];
		
	printf("Enter first text: ");
	read_text(str1, sizeof(str1), 1);

	printf("Enter second text: ");
	read_text(str2, sizeof(str2), 1);

	ptr = max_str(str1, str2);
	if(ptr == NULL)
		printf("Same number of characters.\n");
	else
		printf("Result: %s\n", ptr);
	return 0;
}

char *max_str(char str1[], char str2[])
{
	int i, j;

	i = strlen(str1);
	j = strlen(str2);

	if(i > j)
		return str1; 
	else if(i < j)
		return str2; 
	else
		return NULL;
}
