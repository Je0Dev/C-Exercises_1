#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);
char *find(char str[], char ch, int f); 

int main(void)
{
	char *ptr, ch, str[100];
	int flag;

	printf("Enter text: ");
	read_text(str, sizeof(str), 1);

	printf("Enter character to search: ");
	scanf("%c", &ch);

	printf("Enter choice (0-first, other-last): ");
	scanf("%d", &flag);

	ptr = find(str, ch, flag);
	if(ptr == NULL)
		printf("'%c' is not included in the text\n", ch);
	else
		printf("The rest string is: %s\n", ptr);
	return 0;
}
char *find(char str[], char ch, int f)
{
	char *tmp = NULL; /* Initial value in case the character is not found. */
	while(*str != '\0') 
	{
		if(*str == ch) 
		{
			tmp = str;
			if(f == 0) /* If the character is found and the choice is 0, the loop terminates and the function returns the pointer. Otherwise, tmp points to the place of the last occurrence. */
				break;
		}
		str++;  
	}
	return tmp; 
}
