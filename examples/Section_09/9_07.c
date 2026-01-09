#include <stdio.h>
int main(void)
{
	int ch, sign, val, dig;

	sign = '+';
	dig = 0;
	val = 0; /* val remains 0 until the user enters the first digit. Then, if the user enters a non-digit character the program terminates. */
	printf("Enter number: ");
	while((ch = getchar()) != '\n' && ch != EOF)
	{
		if(ch == ' ' || ch == '\t')
		{
			if(val != 0)
			{
				printf("Error: No spaces between digits\n");
				return 0;
			}
		}
		else if(ch == '+' || ch == '-')
		{
			if(val != 0)
			{
				printf("Error: No signs between digits\n");
				return 0;
			}
			sign = ch;
		}
		else if(ch >= '0' && ch <= '9')
		{
			dig++;
			if(dig > 10)
			{
				printf("Error: Maximum number of digits is passed\n");
				return 0;
			}
			val = 10*val + (ch-'0'); /* To find the numeric value of the digit the ASCII value of 0 is subtracted. */
		}
		else
		{
			printf("Error: Input is not a digit\n");
			return 0;
		}
	}
	if(sign == '-')
		val = -val;
	printf("%d\n", val);
	return 0;
}
