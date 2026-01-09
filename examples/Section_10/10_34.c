#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETTERS 26

int read_text(char str[], int size, int flag);

int main(void)
{
	char str[100], key[LETTERS+1];
	int i, j, len, error;

	printf("Enter text: ");
	len = read_text(str, sizeof(str), 1);

	do
	{
		error = 0;
		printf("Enter key (%d different characters): ", LETTERS);
		read_text(key, sizeof(key), 1);
		if(strlen(key) != LETTERS)
		{
			printf("Error: Key must be of %d characters\n", LETTERS);
			error = 1;
		}
		else	
		{
			for(i = 0; i < LETTERS; i++)
			{
				for(j=i+1; j < LETTERS; j++)
				{
					if(key[i] == key[j])
					{
						error = 1;
						printf("Key characters must be different\n");
						getchar();
						break;
					}
				}
				if(error == 1)
					break;
			}
		}
	}
	while(error != 0);

	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = key[str[i]-'a'];
	}
	printf("Encrypted text: %s\n", str);
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < LETTERS; j++)
		{
			if(str[i] == key[j])
			{
				str[i] = 'a'+j;
				break;
			}
		}
	}
	printf("Original text: %s\n", str);
	return 0;
}
