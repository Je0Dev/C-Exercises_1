#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10

int read_text(char str[], int size, int flag);

int main(void)
{
	char tmp[40], str[NUM][40] = {0};
	int i, j, ch, num, len, max_len, cnt, max_cnt, col;

	num = max_len = 0;
	for(i = 0; i < NUM; i++)
	{
		printf("Enter text: ");
		len = read_text(tmp, sizeof(tmp), 1);
		if(tmp[0] == 'a' && tmp[len-1] == 's')
		{
			strcpy(str[num], tmp);
			num++;
			if(len > max_len)
				max_len = len;
		}
	}
	if(num == 0)
	{
		printf("None string is stored\n");
		return 0;
	}
	printf("Enter character: ");
	ch = getchar();

	max_cnt = 0;
	/* We use the length of the longest string and the number of the stored strings, to search for the character only in those rows and columns where characters are stored. */
	for(j = 0; j < max_len; j++)
	{
		cnt = 0;
		for(i = 0; i < num; i++)
		{
			if(str[i][j] == ch)
				cnt++;
		}
		if(cnt > max_cnt)
		{
			max_cnt = cnt;
			col = j;
		}
	}
	if(max_cnt == 0)
		printf("%c is not stored\n", ch);
	else
		printf("Max appearances of %c is %d in col_%d\n", ch, max_cnt, col+1);
	return 0;
}
