/**********************************************************************
 * This is supposed to print the message "Fatal Error: Abort"
 * and exit when it receives bad data. But when it gets good
 * data, it exits. Why?
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define DIE \
	fprintf(stderr, "Fatal Error: Abort\n"); exit(8);

int main() {
	/* a random value for testing */
	int value;

	value = 1;
	/* there need to be braces around the DIE because it
	 * contains multiple statements. Without the braces,
	 * only the fprintf() is conditional.
	 */
	if (value < 0) {
		DIE;
	}

	printf("We did not die\n");
	return(0);
}

