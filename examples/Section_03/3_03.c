#include <stdio.h>
int main(void)
{
	float i, j, k, avg;
	
	printf("Enter 3 prices: ");	
	scanf("%f%f%f", &i, &j, &k);

	avg = (i+j+k)/3; /* The parentheses are necessary to perform the addition first and then the division. */
	printf("Average = %f\n", avg); 
	return 0;
}
