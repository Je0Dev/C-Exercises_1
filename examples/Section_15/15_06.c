#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
	FILE *fp;
	char flag, str[20], prod[20];
	double prc;

	fp = fopen("test.txt", "w+"); /* Open file for reading and writing. */
	if(fp == NULL)
	{
		printf("Error: fopen() failed\n");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		printf("Enter price: ");
		scanf("%lf", &prc);
		if(prc == -1)
			break;
		getchar();
		printf("Enter product code: ");
		read_text(str, sizeof(str), 1);
		fprintf(fp, "%s %f\n", str, prc);
      }
	getchar();
	printf("Enter product code to search for: ");
	read_text(prod, sizeof(prod), 1);

	flag = 0;
	fseek(fp, 0, SEEK_SET); 
	while(1)
	{
		if(fscanf(fp, "%s%lf", str, &prc) != 2) 
			break;
		if(strcmp(str, prod) == 0)
		{
			flag = 1;
			break; /* Since the product is found exit from the loop. */
		}
	}
	if(flag == 0)
		printf("The %s product is not listed\n", prod);
	else
		printf("The price for product %s is %f\n", prod, prc);
	fclose(fp);
	return 0;
}
