#include <stdio.h>

#define SIZE 10 

void sel_sort(int arr[], int size);
void add_sort(int arr[], int size, int num);

int main(void)
{
	int i, num, a[SIZE];

	for(i = 0; i < SIZE-1; i++) /* Read 9 integers and store them in the array. */
	{
		printf("Enter number: ");
		scanf("%d", &a[i]);
	}
	sel_sort(a, SIZE-1); /* Sort the 9 elements. */
	printf("Insert number in sorted array: ");
	scanf("%d", &num);

	add_sort(a, SIZE-1, num); /* Insert the last integer in the array. */
	for(i = 0; i < SIZE; i++)
		printf("%d\n", a[i]);
	return 0;
}

void add_sort(int arr[], int size, int num)
{
	int i, pos;

	if(num <= arr[0])
		pos = 0;
	else if(num >= arr[size-1]) /* If it greater than the last one, store it in the last position and return. */
	{
		arr[size] = num; 
		return;
	}
	else 
	{
		for(i = 0; i < size-1; i++)
		{
			/* Check all adjacent pairs up to the last one at positions SIZE-3 and SIZE-2 to find the position to insert the number. */
			if(num >= arr[i] && num <= arr[i+1])
				break;
		}
		pos = i+1;
	}
	for(i = size; i > pos; i--)
		arr[i] = arr[i-1]; /* The elements are shifted one position to the right, starting from the last position of the array, that is [SIZE-1], up to the position in which the new number will be inserted. For example, in the last iteration, i = pos+1, so, arr[pos+1] = arr[pos]. */
	arr[pos] = num; /* Store the number. */
}

void sel_sort(int arr[], int size)
{
	int i, j, temp;

	for(i = 0; i < size-1; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				/* Swap values. */
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
