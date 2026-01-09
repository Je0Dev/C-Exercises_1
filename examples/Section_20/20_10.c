#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher(FILE *fp_in, FILE *fp_out, int key);
void decipher(FILE *fp_in, FILE *fp_out, int key);
int read_text(char str[], int size, int flag);

int main(void)
{
	FILE *fp_in, *fp_out;
	char str[100];
	int sel, key;

	while(1) 
	{
		printf("\nMenu selections\n");
		printf("---------------\n");
		printf("1. Cipher\n");
		printf("2. Decipher\n");
		printf("3. Exit\n");

		printf("\nEnter choice: ");
		scanf("%d", &sel);

		switch(sel)
		{
			case 1:
			case 2:
				/* Check whether the input key is valid or not. Since we are using the English alphabet, the valid values are between 1 and 25. */
				do
				{
					printf("Enter key size: ");
					scanf("%d", &key);
				} while(key < 1 || key > 25);

				getchar();
				printf("Input file: ");
				read_text(str, sizeof(str), 1);
				fp_in = fopen(str, "r"); 
				if(fp_in == NULL)
				{
					printf("Error: fopen() for %s failed\n", str);
					exit(EXIT_FAILURE);
				}
				printf("Output file: ");
				read_text(str, sizeof(str), 1);
				fp_out = fopen(str, "w"); 
				if(fp_out == NULL)
				{
					printf("Error: fopen() for %s failed\n", str);
					exit(EXIT_FAILURE);
				}
				if(sel == 1) 
					cipher(fp_in, fp_out, key);
				else
					decipher(fp_in, fp_out, key);

				fclose(fp_in);
				fclose(fp_out);
			break;

			case 3:
			return 0; 

			default:
				printf("\nWrong choice\n");
			break;
		}
	}
	return 0;
}

void cipher(FILE *fp_in, FILE *fp_out, int key)
{
	int ch;

	while(1)
	{
		ch = getc(fp_in); 
		if(ch == EOF)
			return;
		/* Only the lower and upper case characters are encrypted. */
		if(ch >= 'A' && ch <= 'Z')
		{
			ch += key;
			if(ch > 'Z')
				ch -= 26;
		}
		else if(ch >= 'a' && ch <= 'z')
		{
			ch += key;
			if(ch > 'z')
				ch -= 26;
		}
		putc(ch, fp_out);
	}
}

void decipher(FILE *fp_in, FILE *fp_out, int key)
{
	int ch;

	while(1)
	{
		ch = getc(fp_in); 
		if(ch == EOF)
			return;
		/* Only the lower and upper case characters are decrypted. */
		if(ch >= 'A' && ch <= 'Z')
		{
			ch -= key;
			if(ch < 'A') 
				ch += 26; 
		}
		else if(ch >= 'a' && ch <= 'z')
		{
			ch -= key;
			if(ch < 'a') 
				ch += 26; 
		}
		putc(ch, fp_out);
	}
}
