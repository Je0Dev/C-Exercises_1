#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIRMS 20

int read_text(char str[], int size, int flag);

int main(void)
{
	char firm_name[MAX_FIRMS][100], tmp[100];
	int i, j, k, found, tot_grd[MAX_FIRMS] = {0}, firm_grd[MAX_FIRMS][MAX_FIRMS] = {0};

	for(i = 0; i < MAX_FIRMS; i++)
	{
		printf("\nEnter name of firm_%d: ", i+1);
		read_text(firm_name[i], sizeof(firm_name[i]), 1);

		for(j = 0; j < MAX_FIRMS; j++)
		{
			/* A firm does not grade itself. */
			if(i == j)
				continue;
			while(1)
			{
				do
				{
					printf("Enter grade for firm_%d [1-%d]: ", j+1, MAX_FIRMS);
					scanf("%d", &firm_grd[i][j]);
				} while(firm_grd[i][j] < 1 || firm_grd[i][j] > MAX_FIRMS); 
				found = 0;
				/* Check if the grade is already given to another firm. */
				for(k = 0; k < j; k++)
				{
					if(firm_grd[i][k] == firm_grd[i][j]) 
					{
						printf("Error: The grade %d is given\n", firm_grd[i][j]);
						found = 1;
						break;
					}
				}
				if(found == 0)
					break;
			}
			tot_grd[j] += firm_grd[i][j]; /* Each tot_grd[j] holds the total score of the respective firm. */ 
		}
		getchar();
	}
	for(i = 0; i < MAX_FIRMS-1; i++)
	{
		for(j = i+1; j < MAX_FIRMS; j++)
		{
			if(tot_grd[i] < tot_grd[j])
			{
				/* Swap grades and the corresponding names. */
				k = tot_grd[i];
				tot_grd[i] = tot_grd[j];
				tot_grd[j] = k;

				strcpy(tmp, firm_name[j]);
				strcpy(firm_name[j], firm_name[i]);
				strcpy(firm_name[i], tmp);
			}
		}
	}
	for(i = 0; i < MAX_FIRMS; i++)
		printf("%s: %d\n", firm_name[i], tot_grd[i]);
	return 0;
}
