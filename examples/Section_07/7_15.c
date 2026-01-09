#include <stdio.h>
int main(void)
{
	int i, rem, flag, dig_times[10] = {0}; /* This array holds the appearances of each digit. For example, dig_times[0] indicates how many times digit 0 appears. */
	printf("Enter number: ");
	scanf("%d", &i);
	if(i == 0) /* Check if 0 is entered. */
		dig_times[0] = 1;
	while(i != 0)
	{
		rem = i%10;
		if(rem < 0)
			rem = -rem;
		dig_times[rem]++;
		i /= 10;
	}
	flag = 0;
	for(i = 0; i < 10; i++)
	{
		if(dig_times[i] > 1)
		{
			printf("Digit %d appears %d times\n", i, dig_times[i]);
			flag = 1;
		}
	}
	if(flag == 0)
		printf("No digit appears multiple times\n");
	return 0;
}
