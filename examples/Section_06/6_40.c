#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int i, j, num, fails, wins;

	fails = wins = 0;
	srand(time(NULL)); 
	do 
	{
		i = rand()%10+1; /* rand() returns a random positive integer and the % operator constrains it in [0, 9]. We add one to constrain it in [1, 10]. */
		j = rand()%10+1; 
		if(i < j)
			printf("\n%dx%d=", i, j);
		else
			printf("\n%dx%d=", j, i);

		scanf("%d", &num);
		if(num != -1)
		{
			if(num == i*j)
			{
				printf("Correct\n");
				wins++;
			}
			else
			{
				printf("Wrong(answer=%d)\n", i*j);
				fails++;
			}
		}
	} while (num != -1);

	printf("Fails = %d, Wins = %d\n", fails, wins);
	return 0;
}
