#include <stdio.h>
int main(void)
{
	int i, num, sum;

	printf("Enter number > 0: ");
	scanf("%d", &num);
	sum = 0; /* This variable holds the sum of the terms. It is initialized to 0, to make the additions. */ 
	for(i = 1; i <= 2*num-1; i+=2)
		sum += i;
	if(sum == num*num)
		printf("Verified\n");
	else
		printf("Not Verified\n");
	return 0;
}
