#include <stdio.h>
int main(void)
{
	int num2, div;
	double num1;

	printf("Enter positives float and int: ");
	scanf("%lf%d", &num1, &num2); 
	div = num1/num2; /* Suppose that the input values are 7.24 and 4. Since div is declared as integer it becomes 1. */
	printf("%f\n", num1 - (div*num2));
	return 0;
}
