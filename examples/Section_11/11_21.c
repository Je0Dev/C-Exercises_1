#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_end(char str1[], char str2[]);
int read_text(char str[], int size, int flag);

int main(void)
{
	char str1[100], str2[100];
	int i;

	printf("Enter first text: ");
	read_text(str1, sizeof(str1), 1);

	printf("Enter second text: ");
	read_text(str2, sizeof(str2), 1);

	i = str_end(str1, str2);
	if(i == 0)
		printf("%s is not at the end of %s\n", str2, str1);
	else
		printf("%s is at the end of %s\n", str2, str1);
	return 0;
}

int str_end(char str1[], char str2[])
{
	int i, len1, len2;

	len1 = strlen(str1);
	len2 = strlen(str2);

	if(len1 < len2) /* If the length of the second string is greater, the function returns. */
		return 0;
	for(i = 1; i <= len2; i++)
		if(str1[len1-i] != str2[len2-i]) /* If two characters are not the same, it is not needed to compare the rest, so the function returns. */ 
			return 0;
	/* If this point is reached, it means that all compared characters were the same. */ 
	return 1;
}
