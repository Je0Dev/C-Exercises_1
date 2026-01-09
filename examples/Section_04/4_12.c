#include <stdio.h>
int main(void)
{
	unsigned char num, tmp;

	printf("Enter number [0-255]: ");
	scanf("%d", &num);

	tmp = num & 0xF; /* The value of the four lower bits is stored into tmp. 0xF is 1111 in binary. Of course, we could use 15 instead of 0xF. */
	tmp <<= 4; /* Shift the value four places to the left. */
	tmp += num >> 4; /* Add to tmp the value of num shifted four places to the right. */
	printf("%d\n", tmp);
	return 0;
}
