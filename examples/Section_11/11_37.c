#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int read_text(char str[], int size, int flag);
void parse_str(char str[]); 

int main(void)
{
	char str[100];

	printf("Enter text: ");
	read_text(str, sizeof(str), 1);
	parse_str(str);
	return 0;
}

void parse_str(char s[]) 
{
	int dig, uplet_wrd, lowlet_wrd;

	dig = uplet_wrd = lowlet_wrd = 0; 
	while(*s != '\0') 
	{
		while(isspace(*s)) /* Skip the whitespace characters until a word begins. */
			s++;
		if(*s == '\0')
			break;
		/* We check if the word begins with a digit or letter.*/
		if(isdigit(*s))
			dig++;
		else if(isupper(*s))
			uplet_wrd++;
		else if(islower(*s))
			lowlet_wrd++;
		s++;
		if(*s == '\0')
			break;
		while(isspace(*s) == 0) /* Skip the characters of the word; check only for digits. */
		{
			if(isdigit(*s))
				dig++;
			s++;
			if(*s == '\0')
				break;
		}
	}
	printf("UL:%d LL:%d DG:%d\n", uplet_wrd, lowlet_wrd, dig);
}
