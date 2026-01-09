#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(char s1[], char s2[]);
int read_text(char str[], int size, int flag);

int main(void)
{
	char str1[100], str2[100], tmp[100];

	printf("Enter first text: ");
	read_text(str1, sizeof(str1), 1);

	printf("Enter second text: ");
	read_text(str2, sizeof(str2), 1);

	copy(tmp, str1); /* Copy the first string into tmp. */
	copy(str1, str2); /* Copy the second string into str1. */
	copy(str2, tmp); /* Copy the first string into str2. */
	printf("\nFirst text: %s\n", str1);
	printf("Second text: %s\n", str2);
	return 0;
}

void copy(char s1[], char s2[])
{
	while(*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0'; 
}
