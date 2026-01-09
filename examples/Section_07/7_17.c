#include <stdio.h>
int main(void)
{
	int i, j, tmp, bits[32]; /* This array holds the bits of the number, that is 0 or 1. The size is 32, because we assume that the size of an integer is 32 bits. */
	unsigned int num;

	printf("Enter number: ");
	scanf("%d", &tmp);
	if(tmp < 0) 
	{
		tmp = -tmp;
		tmp = ~tmp;
		tmp++;
	}
	num = tmp; 	/* It is stored as positive. */
	i = 0;
	/* Successive divisions by 2 and store each bit in the respective array position. */
	while(num > 0) 
	{
		bits[i] = num & 1; 
		num >>= 1; /* Equivalent to num /= 2. */
		i++;
	}
	printf("Binary form: ");
	/* Display the bits from left to right. */
	for(j = i-1; j >= 0; j--)
		printf("%d", bits[j]);
	return 0;
}
