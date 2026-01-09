#include <stdio.h>
int main(void)
{
	char ch1, ch2;

	printf("Enter characters: ");
	scanf("%c%c", &ch1, &ch2);

	if(ch1 < ch2)
	{
		ch1++;
		while(ch1 != ch2)
		{
			printf("%c", ch1);
			ch1++;
		}
	}
	else
	{
		ch2++;
		while(ch2 != ch1)
		{
			printf("%c", ch2);
			ch2++;
		}
	}
	return 0;
}
