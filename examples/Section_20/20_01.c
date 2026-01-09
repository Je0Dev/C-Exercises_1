#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char *tot_str;
	int i, tot_chars;

	if(argc == 1) /* Check if the command line contains only the name of the program. */
	{
		printf("Missing arguments ...\n");
		exit(EXIT_FAILURE);
	}
	tot_chars = 0; /* It counts the characters of all arguments. */
	for(i = 1; i < argc; i++) /* Remember that argv[1] points to the first argument, argv[2] to the second one, and so on. argv[0] points to the name of the program. */
		tot_chars += strlen(argv[i]);

	tot_str = (char*) malloc(tot_chars+1); /* Allocate an extra place for the null character. */
	if(tot_str == NULL)
	{
		printf("Error: Not available memory\n");
		exit(EXIT_FAILURE);
	}
	*tot_str = '\0'; /* Store the null character. */
	for(i = 1; i < argc; i++)
		strcat(tot_str, argv[i]);

	printf("The merged string is: %s\n", tot_str);
	free(tot_str);
	return 0;
}
