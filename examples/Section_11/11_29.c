#include <stdio.h>

int mcd(int a, int b);

int main(void)
{
	int num1, num2;

	do
	{
		printf("Enter the first number: ");
		scanf("%d", &num1);

		printf("Enter the second number (equal or less than the first one): ");
		scanf("%d", &num2);
	} while((num2 > num1) || (num1 <= 0) || (num2 <= 0));

	printf("MCD of %d and %d is %d\n", num1, num2, mcd(num1, num2));
	return 0;
}

int mcd(int a, int b)
{
	int r;

	while(1)
	{
		r = a%b;
		if(r == 0)
			return b;
		else /* According to the algorithm, we divide b by r, so we change the values of a and b. */
		{
			a = b;
			b = r;
		}
	}
}
