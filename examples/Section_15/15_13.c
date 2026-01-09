#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 

int main(void)
{
	FILE *fp;
	int i, arr[SIZE] = {10, 20, 30, 40, 50};

	fp = fopen("test.bin", "w+b"); /* Open binary file for reading and writing. */
	if(fp == NULL)
	{
		printf("Error: fopen() failed\n");
		exit(EXIT_FAILURE); 
	}
	fwrite(arr, sizeof(int), SIZE, fp); 

	printf("Enter new value: ");
	scanf("%d", &i);
	fseek(fp, 2*sizeof(int), SEEK_SET); /* Since each integer is 4 bytes, fseek() moves the file pointer 2*sizeof(int) = 8 bytes from the beginning of the file to get to the third integer. */
	fwrite(&i, sizeof(int), 1, fp); 

	fseek(fp, 0, SEEK_SET);
	if(fread(arr, sizeof(int), SIZE, fp) != SIZE)
	{
		fclose(fp);
		printf("Error: fread() failed\n");
		exit(EXIT_FAILURE);
	}
	printf("\n***** File contents *****\n");
	for(i = 0; i < SIZE; i++)
		printf("%d\n", arr[i]);

	fclose(fp);
	return 0;
}
