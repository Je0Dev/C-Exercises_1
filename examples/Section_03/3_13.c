#include <stdio.h>
int main(void)
{
	int i;
	float j;

	printf("Enter positive number: ");
	scanf("%d", &i);

	i = i+5;
	j = (float)i/10;
	i = (int)j * 10; /* Cut off the last digit. */
	printf("%d\n", i);
	return 0;
}
