#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);
void find(char *p, int ch, int cnt);

int main(void)
{
	char ch, str[100];

	printf("Enter text: ");
	read_text(str, sizeof(str), 1);

	printf("Enter character: ");
	ch = getchar();
	find(str, ch, 0);
	return 0;
}

void find(char *p, int ch, int cnt)
{
	p = strchr(p, ch);
	if(p == NULL) 
		printf("%d\n", cnt);
	else
		find(p+1, ch, cnt+1);
}
