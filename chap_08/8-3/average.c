/**********************************************************************
 * Write a program to average n numbers.
 **********************************************************************/

#include <stdio.h>

char line[100];                 /* line of input from keyboard */

float number;                   /* the current number */
float count;                    /* how many values we've seen */
float total;                    /* total of the values we've seen */

int main() {
	total = 0.0;
	count = 0.0;

	while (1) {
		printf("Enter a number (0 to end): ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%f", &number);

		if (number == 0.0) {
			printf("\nAverage of %0.0f numbers: %0.3f\n", count, total / count);
			return(0);
		}

		total += number;
		count += 1.0;
	}
}

