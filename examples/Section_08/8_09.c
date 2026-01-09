#include <stdio.h>
int main(void)
{
	int *p, i;

	p = &i;
	*p = 1;
	while(*p <= 10)
	{
		printf("%d\n", *p);
		(*p)++; /* As we'll see later, parentheses are needed for priority reasons. */
	}
	return 0;
}
