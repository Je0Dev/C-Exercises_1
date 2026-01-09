#include <stdio.h>

#define LESSONS	3
#define STUDENTS	5

int main(void)
{
	int i, j;
	float grd, stud_grd, sum_grd;

	sum_grd = 0;
	for(i = 0; i < STUDENTS; i++)
	{
		printf("***** Student_%d\n", i+1);
		stud_grd = 0; /* This variable holds the sum of a student's grades in all courses. It is initialized to 0 for each one. */
		for(j = 0; j < LESSONS; j++)
		{
			printf("Enter grade for lesson %d: ", j+1);
			scanf("%f", &grd);
			stud_grd += grd;
			sum_grd += grd; /* This variable holds the sum of all grades. */
		}
		printf("Average grade for student_%d is %.2f\n", 
			i+1, stud_grd/LESSONS);
	}
	printf("\nTotal average grade is %.2f\n", 
		sum_grd/(STUDENTS*LESSONS));
	return 0;
}
