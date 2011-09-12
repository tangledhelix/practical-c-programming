#include <stdio.h>

char line[100];             /* line of input data */
int height;                 /* the height of the triangle */
int width;                  /* the width of the triangle */
int area;                   /* area of the triangle (computed) */

int main() {
	printf("Enter width height? ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d %d", &width, &height);

	area = (width * height) / 2;
	printf("The area is %d\n", area);

	return(0);
}
