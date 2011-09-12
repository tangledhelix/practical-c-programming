/**********************************************************************
 * Write a program to print out the multiplication table.
 **********************************************************************/

#include <stdio.h>

int x_axis;                 /* x-axis of the table */
int y_axis;                 /* y-axis of the table */

int main() {

	printf("\n    ");
	for (x_axis = 1; x_axis <= 12; ++x_axis) {
		printf("%4d", x_axis);
	}
	printf("\n");
	printf("   +-----------------------------------------------\n");

	for (y_axis = 1; y_axis <= 12; ++y_axis) {
		printf("%2d |", y_axis);

		for (x_axis = 1; x_axis <= 12; ++x_axis) {
		    printf("%4d", x_axis * y_axis);
		}
		printf("\n");
	}

	return(0);
}

