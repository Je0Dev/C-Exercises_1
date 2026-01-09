#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

#define SIZE 100

struct student
{
	char name[50]; 
	int code;
	float grd;
};

int main(void)
{
	struct student *ptr, stud[SIZE]; 

	for(ptr = stud; ptr < stud+SIZE; ptr++) /* ptr is increased to point to the next structure. */
	{
		printf("\nEnter name: ");
		read_text(ptr->name, sizeof(ptr->name), 1);

		printf("Enter code: ");
		scanf("%d", &ptr->code);

		printf("Enter grade: ");
		scanf("%f", &ptr->grd);

		printf("\nN: %s C: %d G: %.2f\n", ptr->name, ptr->code, ptr->grd);
		getchar();
	}
	return 0;
}
