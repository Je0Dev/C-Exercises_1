#include <stdio.h>

#define SIZE 10

int main(void)
{
	int i, num, arr[SIZE] = {0}; /* Since the value 0 is not an acceptable value, we use it as a special value to indicate that an element is unassigned. */
	for(i = 0; i < SIZE; i++)
	{
		do
		{
			printf("Enter number: ");
			scanf("%d", &num);
			if(num == 0 || num == -1)
				printf("Not valid input !!!\n");
		} while(num == 0 || num == -1);

		if(i & 1) /* Check if the position is odd. */
		{
			if(num & 1) /* Store the number only if both the position and the number are odd. */
				arr[i] = num;
		}
		else
		{
			if((num & 1) == 0) /* Store the number only if both the position and the number are even. */
				arr[i] = num;
		}
	}
	printf("\n*** Array elements ***\n");
	for(i = 0; i < SIZE; i++)
	{
		if(arr[i] == 0)
			arr[i] = -1;
		printf("%d\n", arr[i]);
	}
	return 0;
}
