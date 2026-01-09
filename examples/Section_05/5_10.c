#include <stdio.h>
int main(void)
{
	float income, tax;

	printf("Enter income: ");
	scanf("%f", &income);

	if(income <= 12000)
		tax = 0;
	else if(income <= 14000)
		tax = (income - 12000)*0.15;
	else if(income <= 30000)
		tax = (2000*0.15) + (income - 14000)*0.3; /* 2000 is the difference of 14000-12000. */
	else
		tax = (2000*0.15) + (16000*0.3) + (income - 30000)*0.4; /* 16000 is the difference of 30000-14000. */
	printf("Tax = %.2f\n", tax);
	return 0;
}
