#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	FILE *fp1, *fp2;
	char flag, str1[100], str2[100];

	printf("Enter first file: ");
	read_text(str1, sizeof(str1), 1);

	fp1 = fopen(str1, "r");
	if(fp1 == NULL)
	{
		printf("Error: fopen() for %s failed\n", str1);
		exit(EXIT_FAILURE); 
	}
	printf("Enter second file: ");
	read_text(str1, sizeof(str1), 1);

	fp2 = fopen(str1, "r");
	if(fp2 == NULL)
	{
		fclose(fp1);
		printf("Error: fopen() for %s failed\n", str1);
		exit(EXIT_FAILURE); 
	}
	flag = 0;
	while(1)
	{
		if((fgets(str1, sizeof(str1), fp1) == NULL) 
			|| (fgets(str2, sizeof(str2), fp2) == NULL))
			break; /* We check if a read error occurred or the end of a file is reached. In either case, the loop terminates. */
		if(strcmp(str1, str2) == 0)
		{
			printf("The same line is: %s\n", str1);
			flag = 1;
			break; /* Since a common line is found, exit from the loop. */
		}
	}
	if(flag == 0)
		printf("There is no common line\n");

	fclose(fp1);
	fclose(fp2);
	return 0;
}
