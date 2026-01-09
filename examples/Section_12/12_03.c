#include <stdio.h>

int binary_search(int arr[], int size, int num);

int main(void)
{
	int num, pos, arr[] = {10, 20, 30, 40, 50, 60, 70}; 

	printf("Enter number to search: ");
	scanf("%d", &num);

	pos = binary_search(arr, 7, num);
	if(pos == -1)
		printf("%d isn't found\n", num);
	else
		printf("%d is found in position %d\n", num, pos);
	return 0;
}

int binary_search(int arr[], int size, int num)
{
	int start, end, middle;

	start = 0;
	end = size-1;
	while(start <= end)
	{
		middle = (start+end)/2;

		if(num < arr[middle])
			end = middle-1;
		else if(num > arr[middle])
			start = middle+1;
		else
			return middle;
	}
	return -1; /* If the execution reaches this point it means that the number was not found. */
}
