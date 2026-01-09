#include <stdio.h>

void swap(float *ptr1, float *ptr2);

int main(void)
{
	float i, j;

	printf("Enter numbers: ");
	scanf("%f%f", &i, &j);
	swap(&i, &j);
	printf("i = %f j = %f\n", i, j);
	return 0;
}

void swap(float* ptr1, float* ptr2) 
{
	float m;

	m = *ptr1; /* Equivalent to m = i; */
	*ptr1 = *ptr2; /* Equivalent to i = j; */
	*ptr2 = m; /* Equivalent to j = m = i; */
}
