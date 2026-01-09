#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5

int main(void)
{
	int i, j, determ, arr[ROWS][ROWS];

	determ = 1; /* Initialize the determinant. */
	srand(time(NULL)); 
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < ROWS; j++)
		{
			if(i > j) 
				arr[i][j] = 0; /* The elements below the main diagonal should be set to 0. */
			else 
				arr[i][j] = rand()%7-3; /* The result of rand()%7 is an integer in [0, 6]. By subtracting 3, the integer is constrained in [-3, 3]. */
			printf("%3d", arr[i][j]);
			if(i == j) /* Check if the element belongs in the main diagonal. */
				determ *= arr[i][j]; 
		}
		printf("\n"); /* Used to separate the rows of the arrays. */
	}
	printf("\nThe determinant is: %d\n", determ);
	return 0;
}
