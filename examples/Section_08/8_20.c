#include <stdio.h>

#define SIZE 10

int main(void)
{
	int i, max_pos, min_pos;
	float max, min, arr[SIZE];

	max = -1;
	min = 11;
	for(i = 0; i < SIZE; i++)
	{
		do
		{
			printf("Enter grade: ");
			scanf("%f", arr+i); 
		} while(*(arr+i) > 10 || *(arr+i) < 0); /* Check if the grade is within [0, 10]. */
		if(*(arr+i) > max) 
		{
			max = *(arr+i);
			max_pos = i;
		}
		if(*(arr+i) < min) 
		{
			min = *(arr+i);
			min_pos = i;
		}
	}
	printf("Max grade is %.2f in pos #%d\nMin grade is %.2f in pos #%d\n", max, max_pos, min, min_pos);
	return 0;
}
