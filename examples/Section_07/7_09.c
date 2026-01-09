#include <stdio.h>

#define SIZE 100

int main(void)
{
	int i, min_pos, max_pos;
	float sum, min_grd, max_grd, grd[SIZE];

	sum = 0; 
	max_grd = -1;
	min_grd = 11; 
	for(i = 0; i < SIZE; i++)
	{
		printf("Enter grade in [0-10]: ");
		scanf("%f", &grd[i]); 
		/* There are several ways to check whether the input grade is valid. In C.7.14, we'll use do-while. */
		while(grd[i] < 0 || grd[i] > 10)
		{
			printf("Error - Enter new grade in [0-10]: ");
			scanf("%f", &grd[i]); 
		} 
		sum += grd[i];
		if(grd[i] > max_grd)
		{
			max_grd = grd[i];
			max_pos = i; /* Store the position with the best grade. */
		}
		if(grd[i] < min_grd)
		{
			min_grd = grd[i];
			min_pos = i; /* Store the position with the worst grade. */
		}
	}
	printf("Avg: %.2f H(%d): %.2f L(%d): %.2f\n", sum/SIZE, max_pos, max_grd, min_pos, min_grd);
	return 0;
}
