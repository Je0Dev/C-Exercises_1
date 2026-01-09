#include <stdio.h>
int main(void)
{
	int i, num;

	for(;;) /* Create an infinite loop. */
	{
		printf("Enter number [1-10]: ");
		scanf("%d", &num);
		if((num >= 1) && (num <= 10))
			break; /* If the user enters a number within [1, 10], the loop terminates. */
	}
	for(i = 1; i <= 10; i++)
		printf("%d * %d = %d\n", i, num, i*num);
	return 0;
}
