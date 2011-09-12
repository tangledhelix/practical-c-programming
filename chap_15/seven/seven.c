/* Question:
 * Reads in a list of five numbers and counts the number of
 * sevens and the number of threes in the input. Why does it
 * return wrong counts?
 */

/* Answer:
 * data[] is declared as an array of 5 positions, 0-4, but
 * we later assign a valud to data[5]. To fix, start
 * the count from 0, not 1. Alternate, but dumb, fix,
 * is to declare it as an array of 6 positions.
 */

#include <stdio.h>

char line[100];             /* line of keyboard input */

int data[5];                /* the data to count 3 and 7 in */
int three_count;            /* the number of 3s in the data */
int seven_count;            /* number of 7s in the data */
int index;                  /* index into the data */

int main() {

	seven_count = 0;
	three_count = 0;

	printf("Enter 5 numbers\n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d %d %d %d %d",
			&data[1], &data[2], &data[3],
			&data[4], &data[5] );

	for (index = 1; index <= 5; ++index) {
		if (data[index] == 3) {
			++three_count;
		}

		if (data[index] == 7) {
			++seven_count;
		}
	}

	printf("Threes %d Sevens %d\n", three_count, seven_count);
	return(0);
}
