/**********************************************************************
 * PosNeg takes a series of numbers and counts how many are positive
 * and how many are negative.
 *
 * Enter '0' to end the program and display the counters
 **********************************************************************/

#include <stdio.h>

char line[100];             /* a line of input from the keyboard */

float value;                /* the current value */

int pos_ctr = 0;            /* how many positives we've seen */
int neg_ctr = 0;            /* how many negatives we've seen */

int main(void) {

	while (1) {

		printf("Enter value or 0 to quit: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%f", &value);

		if (value == 0.0) {
			printf("Saw %d positive, %d negative numbers\n",
					pos_ctr, neg_ctr);
			return(0);
		}

		if (value > 0.0) {
			++pos_ctr;
		} else if (value < 0.0) {
			++neg_ctr;
		} else {
			printf("Error: should never get here.\n");
			return(-1);
		}
	}
}

