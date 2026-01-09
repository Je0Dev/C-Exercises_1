#include <stdio.h>
int main(void)
{
	int i, suc, fail;
	float grd, sum_suc, sum_fail;

	suc = fail = 0;
	sum_suc = sum_fail = 0;
	for(i = 0; i < 100; i++)
	{
		printf("Enter grade: ");
		scanf("%f", &grd);

		if(grd == -1)
			break;
		if(grd > 10 || grd < 0)
		{
			printf("Wrong grade, try again ...\n");
			i--; /* If the input grade is out of [0, 10], the grade is ignored and i is decremented to repeat the insertion. */
			continue;
		}
		if(grd >= 5)
		{
			suc++;
			sum_suc += grd;
		}
		else
		{
			fail++;
			sum_fail += grd;
		}
	}
	if(i != 0)
	{
		if(suc)
			printf("Avg(+) = %.2f\n", sum_suc/suc);
		else
			printf("Everybody failed\n");

		if(fail)
			printf("Avg(-) = %.2f\n", sum_fail/fail);
		else
			printf("None failed\n");
	}
	return 0;
}
