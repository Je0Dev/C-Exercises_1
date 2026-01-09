#include <stdio.h>
int main(void)
{
	int i, num; 
	double fact;

	printf("Enter number within [0, 170]: ");
	scanf("%d", &num);

	if(num >= 0 && num <= 170)
	{
		fact = 1; /* This variable holds the factorial of the input number. It is initialized to 1, to make the multplications. */
		for(i = 1; i <= num; i++)
			fact = fact*i;
		/* If the user enters 0, the loop won't be executed because the condition (i <= num) is false (i=1 and num=0). Therefore, the program would display the initial value of fact, that is, 1. And this is correct, since 0! = 1. */
		printf("Factorial of %d is %e\n", num, fact);
	}
	else
		printf("Error: Number should be within [0, 170]\n"); 
	return 0;
}
