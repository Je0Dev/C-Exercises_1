#include <stdio.h>
int main(void)
{
	float *ptr1, *ptr2, i, j, tmp;

	/* The pointers should be initialized before used in scanf(). */
	ptr1 = &i;
	ptr2 = &j;

	printf("Enter values: ");
	scanf("%f%f", ptr1, ptr2); /* Store the input values in the addresses pointed to by the pointers. */
	tmp = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = tmp;

	if(*ptr1 > *ptr2)
		printf("%f\n", *ptr1);
	else
		printf("%f\n", *ptr2);
	return 0;
}
