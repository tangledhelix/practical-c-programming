/**********************************************************************
 * Write a program to compute the area and perimeter of a rectangle
 * with a width of three inches and a height of five inches.
 **********************************************************************/

#include <stdio.h>

int width;          /* width of rectangle in inches */
int height;         /* height of rectangle in inches */

int area;           /* area of rectangle */
int perimeter;      /* perimeter of rectangle */

int main() {
	width = 3;
	height = 5;

	area = width * height;
	printf("area = %d square inches\n", area);

	perimeter = (width * 2) + (height * 2);
	printf("perimeter = %d inches\n", perimeter);

	return(0);
}

