#include <stdio.h>

double power(double a, int b);

int main(void)
{
	int exp;
	double base;

	printf("Enter base and exponent: ");
	scanf("%lf%d", &base, &exp);
	printf("%f power %d = %f\n", base, exp, power(base, exp));
	return 0;
}

double power(double a, int b)
{
	int i, exp;
	double val;

	val = 1; /* Necessary initialization. */
	exp = b;
	if(exp < 0) /* If the exponent is negative, make it positive. */
		exp = -exp;
	for(i = 0; i < exp; i++)
		val *= a;  
	if(b < 0)
		val = 1/val;
	return val;
}
