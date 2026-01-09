#include <stdio.h>
int main(void)
{
	int i, grd, studs_num, times, min_grd, max_grd, sum_grd;

	printf("Enter number of students: ");
	scanf("%d", &studs_num);

	if(studs_num <= 0)
	{
		printf("Wrong number of students\n");
		return 0; /* Program termination. */ 
	}
	min_grd = 11;
	max_grd = -1;
	sum_grd = 0;
	for(i = 0; i < studs_num; i++)
	{
		printf("Enter grade [0-10]: ");
		scanf("%d", &grd); 

		if(grd < min_grd)
			min_grd = grd;
		if(grd > max_grd)
		{
			max_grd = grd;
			times = 1; /* First appearance of the new maximum grade. */
		}
		else if(max_grd == grd)
			times++;

		sum_grd += grd;
	}
	printf("Min:%d Max:%d (appeared %d times) Avg:%.2f\n", min_grd, max_grd, times, (float)sum_grd/studs_num);
	return 0;
}
