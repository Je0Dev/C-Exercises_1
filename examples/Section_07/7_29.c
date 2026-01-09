#include <stdio.h>

#define ROWS 3
#define COLS 3

int main(void)
{
	int i, j, sum, tmp, arr[ROWS][COLS];

	sum = tmp = 0;
	for(i = 0; i < ROWS; i++)
	{
		/* We find the sums of the diagonals. */
		for(j = 0; j < COLS; j++)
		{
			printf("Enter element arr[%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
			if(i == j)
				sum += arr[i][j];
			if(i+j == ROWS-1) /* Check if the element belongs in the secondary diagonal. */
				tmp += arr[i][j];
		}
	}
	if(sum != tmp)
	{
		printf("Not magic square -> Sum_main_diag: %d Sum_sec_diag: %d\n", sum, tmp);
		return 0;
	}
	for(i = 0; i < ROWS; i++)
	{
		/* Initialize the variable which calculates the sum of the elements of each row. */
		tmp = 0;
		for(j = 0; j < COLS; j++)
			tmp += arr[i][j];

		if(sum != tmp)
		{
			printf("Not magic square -> Sum_row_%d: %d Sum_diag: %d\n", i+1, tmp, sum);
			return 0;
		}
	}
	for(i = 0; i < COLS; i++)
	{
		tmp = 0; /* Initialize the variable which calculates the sum of the elements of each column. */
		for(j = 0; j < ROWS; j++)
			tmp += arr[j][i];

		if(sum != tmp)
		{
			printf("Not magic square -> Sum_col_%d: %d Sum_diag: %d\n", i+1, tmp, sum);
			return 0;
		}
	}
	printf("Magic square !!!\n");
	return 0;
}
