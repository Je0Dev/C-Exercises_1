#include <stdio.h>
int main(void)
{
	int i, k, m;
	float grd, sum_suc, sum_fail, arr1[100], arr2[100];

	sum_suc = sum_fail = 0;
	k = m = 0; 
	for(i = 0; i < 100; i++)
	{
		printf("Enter grade: ");
		scanf("%f", &grd);
		if(grd == -1)
			break;

		if(grd >= 5 && grd <= 10)
		{
			sum_suc += grd;
			arr1[k] = grd;
			k++; /* The variable k indicates how many grades are stored into arr1. We could write arr1[k++] = grd; We use two statements to make it clearer. */
		}
		else if(grd >= 0 && grd < 5)
		{
			sum_fail += grd;
			arr2[m] = grd;
			m++; 
		}
	}
	if(i != 0)
	{
		if(k != 0)
			printf("\nSuccess_Avg: %.2f\n", sum_suc/k);
		else
			printf("\nAll students failed\n");

		if(m != 0)
			printf("\nFail_Avg: %.2f\n", sum_fail/m);
		else
			printf("\nAll students passed\n");
	}
	return 0;
}
