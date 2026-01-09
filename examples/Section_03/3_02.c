#include <stdio.h>
int main(void)
{
	int i, j; 

	printf("Enter 2 integers (the second should not be 0):");
	scanf("%d%d", &i, &j); 
	printf("Sum:%d Diff:%d Prod:%d Div:%f\n", i+j, i-j, i*j, (double)i/j); /* Cast i to double, in order to display the decimal part of the division. */
	return 0;
}
