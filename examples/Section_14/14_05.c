#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_cpy(char *trg, const char *src);
int read_text(char str[], int size, int flag);

int main(void)
{
	char *trg, src[100];
	int len;

	printf("Enter text: ");
	len = read_text(src, sizeof(src), 1);
	/* Allocate memory to store the input string and the null character. */
	trg = (char*) malloc(len+1);
	if(trg == NULL)
	{
		printf("Error: Not available memory\n");
		exit(EXIT_FAILURE);
	}
	printf("Copied text: %s\n", str_cpy(trg, src));
	free(trg);
	return 0;
}

char *str_cpy(char *trg, const char *src)
{
	int i = 0;
	while(*(src+i) != '\0') /* Or else, while(src[i] != '\0')*/
	{
		*(trg+i) = *(src+i); /* Or else, trg[i] = src[i]; */
		i++;
	}
	*(trg+i) = '\0'; /* Add the null character. */
	return trg;
}
