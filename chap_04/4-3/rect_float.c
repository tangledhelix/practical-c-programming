/**********************************************************************
 * Modify previous program to work with floating point numbers.
 * Use width 6.8, height 2.3.
 **********************************************************************/

#include <stdio.h>

/* float version */

float width;          /* width of rectangle in inches */
float height;         /* height of rectangle in inches */

float area;           /* area of rectangle */
float perimeter;      /* perimeter of rectangle */

int main() {
	width = 6.8;
	height = 2.3;

	area = width * height;
	printf("area = %f square inches\n", area);

	perimeter = (width * 2.0) + (height * 2.0);
	printf("perimeter = %f inches\n", perimeter);

	return(0);
}

