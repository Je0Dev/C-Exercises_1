#include <stdio.h>
int main(void)
{
	int i, j, lines;

	printf("Enter lines: ");
	scanf("%d", &lines);

	for(i = 0; i < lines; i++)
	{
		for(j = 0; j <= i; j++)
			printf("* "); /* Add a space character after '*'. */
		printf("\n"); /* Change line to display the next group of '*'. */  
	}
	return 0;
}
