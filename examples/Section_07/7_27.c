#include <stdio.h>

#define ROWS 5

int main(void)
{
	int i, j, t[ROWS][ROWS]; 

	printf("Enter [0][0] element: ");
	scanf("%d", &t[0][0]);
	/* Read the remaining values for the first row. */
	for(i = 1; i < ROWS; i++)
	{
		printf("Enter [0][%d] element: ", i);
		scanf("%d", &t[0][i]);
	}
	/* Read the remaining values for the first column. */
	for(i = 1; i < ROWS; i++)
	{
		printf("Enter [%d][0] element: ", i);
		scanf("%d", &t[i][0]);
	}
	/* Create the Toeplitz matrix. */
	for(i = 0; i < ROWS-1; i++)
		for(j = 0; j < ROWS-1; j++)
			t[i+1][j+1] = t[i][j]; /* We traverse the array t and make each element equal to the upper left, except the elements of the first row and column. */
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < ROWS; j++)
			printf("%3d", t[i][j]);
		printf("\n"); 
	}
	return 0;
}
