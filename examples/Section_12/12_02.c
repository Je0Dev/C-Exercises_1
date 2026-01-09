#include <stdio.h>

#define SIZE 10

int num_occurs(int arr[]);

int main(void)
{
	int i, arr[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		printf("Enter number: ");
		scanf("%d", &arr[i]);
	}
	printf("\nMax occurrences is %d\n", num_occurs(arr));
	return 0;
}

int num_occurs(int arr[])
{
	int i, j, k, max_times;

	max_times = 1;
	for(i = 0; i < SIZE; i++)
	{
		k = 1; /* Each number appears once at least. */
		for(j = i+1; j < SIZE; j++) /* Compare arr[i] with the rest elements. */
		{
			if(arr[i] == arr[j]) 
				k++; 
		}
		if(k > max_times)
			max_times = k;
	}
	return max_times;
}
