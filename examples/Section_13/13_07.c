#include <stdio.h>

struct coord 
{
	double x; 
	double y; 
};

struct rectangle 
{
	struct coord point_A; /* First diagonal point. */
	struct coord point_B; /* Second diagonal point. */
};

double rect_area(struct coord *c1, struct coord *c2); 

int main(void)
{
	struct rectangle rect; 

	printf("Enter the x and y coords of the first point: ");
	scanf("%lf%lf", &rect.point_A.x, &rect.point_A.y);

	printf("Enter the x and y coords of the second point: ");
	scanf("%lf%lf", &rect.point_B.x, &rect.point_B.y);

	printf("Area: %f\n", 
rect_area(&rect.point_A, &rect.point_B));
	return 0;
}

double rect_area(struct coord *c1, struct coord *c2)
{
	double base, height;

	if(c1->x > c2->x)
		base = c1->x - c2->x;
	else
		base = c2->x - c1->x;

	if(c1->y > c2->y)
		height = c1->y - c2->y;
	else
		height = c2->y - c1->y;

	return base*height; /* Return the area. */
}
