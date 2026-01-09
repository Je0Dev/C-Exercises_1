#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CNTRS    50
#define MONTHS   12

void bubble_sort(char str[][100], int arr[]);
int read_text(char str[], int size, int flag);

int main(void)
{
	char cntr[CNTRS][100], str[100];
	int i, j, tmp, flag, tour[CNTRS] = {0};

	for(i = 0; i < CNTRS; i++)
	{
		printf("Enter name of country_%d: ", i+1);
		read_text(cntr[i], sizeof(cntr[i]), 1);

		for(j = 0; j < MONTHS; j++)
		{
			printf("Enter tourists of month_%d: ", j+1);
			scanf("%d", &tmp);
			tour[i] += tmp; /* This array holds the annual number of tourists for each country. */
		}
		getchar();
	}
	printf("Enter country to search: ");
	read_text(str, sizeof(str), 1);

	flag = 0;
	for(i = 0; i < CNTRS; i++)
	{
		if(strcmp(str, cntr[i]) == 0)
		{
			flag = 1;
			printf("%d tourists visited %s\n", tour[i], str);
			break;
		}
	}
	if(flag == 0)
		printf("%s not registered\n", str);

	bubble_sort(cntr, tour); /* Sort the tourist array and update the countries array in parallel. */			
	printf("\n***** Tourists in decrease order *****\n");
	for(i = 0; i < 5; i++)
		printf("%d.%s\t%d\n", i+1, cntr[i], tour[i]);
	/* Check if more than one country ties in the fifth place. */
	while((tour[i] == tour[4]) && i < CNTRS)
	{
		printf("%d.%s\t%d\n", i+1, cntr[i], tour[i]);
		i++;
	}
	return 0;
}

void bubble_sort(char str[][100], int arr[])
{
	char temp[100];
	int i, j, k, reorder;

	for(i = 1; i < CNTRS; i++)
	{
		reorder = 0;
		for(j = CNTRS-1; j >= i; j--)
		{
			if(arr[j] > arr[j-1]) /* Parallel swapping of the tourist numbers and the respective countries. */ 
			{
				k = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = k;

				strcpy(temp, str[j]);
				strcpy(str[j], str[j-1]);
				strcpy(str[j-1], temp);
				reorder = 1;
			}
		}
		if(reorder == 0)
			return;
	}
}
