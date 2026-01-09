#include <stdio.h>

double f(double x);

int main(void)
{
	int i, a, b, n;
	double step, x, area;

	do
	{
		printf("Enter number of intervals: ");
		scanf("%d", &n);
	} while(n <= 0);

	do
	{
		printf("Enter low and up limit (a < b): ");
		scanf("%d%d", &a, &b);
	} while(a >= b); 

	step = (double)(b-a)/n;
	x = a;
	area = 0;
	for(i = 0; i < n; i++) 
	{
		area += 0.5*step*(f(x)+f(x+step));
		x += step;
	}
	printf("Calculus = %f\n", area);
	return 0;
}

double f(double x) /* The reason we're using a function is that if we've to calculate another integral it is easy to change the code in the function. */
{
	return x*x;
}
