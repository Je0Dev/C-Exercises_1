#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *rvs_str;
	int i, j, len;

	if(argc == 1) 
	{
		printf("Missing string arguments ...\n");
		exit(EXIT_FAILURE);
	}
	for(i = 1; i < argc; i++)
	{
		len = strlen(argv[i]);
		rvs_str = (char*) malloc(len+1); /* Allocate one extra place for the null character. */
		if(rvs_str == NULL)
		{
			printf("Error: Not available memory\n");
			exit(EXIT_FAILURE);
		}
		for(j = 0; j < len; j++)
			rvs_str[j] = argv[i][len-1-j]; /* The last character is stored in position len-1. */
		
		rvs_str[j] = '\0'; /* Terminate the string. */
		printf("Reverse of %s is: %s\n", argv[i], rvs_str);
		free(rvs_str);
	}
	return 0;
}
