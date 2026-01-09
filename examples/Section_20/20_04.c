#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int i, j, rows, cols;
	double **arr, sum_line;

	if(argc < 3)
		printf("Error: missing arguments...\n");
	else if(argc == 3)
	{
		rows = atoi(argv[1]); /* Convert the second argument to integer. */
		cols = atoi(argv[2]); /* Do the same for the third argument. */
		srand(time(NULL)); 
		arr = (double**) malloc(rows * sizeof(double*)); 
		if(arr == NULL)
		{
			printf("Error: Not available memory\n");
			exit(EXIT_FAILURE);
		}
		for(j = 0; j < rows; j++)
		{
			arr[j] = (double*) malloc(cols * sizeof(double));
			if(arr[j] == NULL)
			{
				printf("Error: Not available memory\n");
				exit(EXIT_FAILURE);
			}
		}
		for(i = 0; i < rows; i++)
		{
			sum_line = 0;
			for(j = 0; j < cols-1; j++)
			{
				arr[i][j] = (rand()%101/(cols-1))/100.0;
				sum_line += arr[i][j]; /* As an example, assume that the number of columns is 5. For the first four row's elements rand()%101 generates an integer in [0, 100]. Dividing it by the number of the columns minus 1, that is, 4, we get an integer in [0, 25] and dividing that integer with 100.0 we get a number in [0, 0.25]. In this way, the sum of the first four elements is constrained in [0, 1]. */
			}
			arr[i][j] = 1-sum_line; /* To satisfy the requirement that the sum of the elements of each row must be equal to 1, the value of the last element is calculated by subtracting from 1 the sum of the rest elements. */	
		}
		for(i = 0; i < rows; i++)
		{
			for(j = 0; j < cols; j++)
			   printf("%6.2f", arr[i][j]);

			printf("\n");
		}
		for(j = 0; j < rows; j++)
			free(arr[j]);
		free(arr);
	}
	else
		printf("Error: too many arguments...\n");
	return 0;
}
