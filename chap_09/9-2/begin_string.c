/**********************************************************************
 * Write a function begins( string1, string2 ) that returns true if
 * string1 begins
 * string2. Write a program to test the function.
 **********************************************************************/

#include <stdio.h>

int begins(char string1[], char string2[]) {
	int i = 0;          /* index into a string */

	while (1) {
	
		/* If we reach the end of the test string without returning
		 * false, then the prior bits must match. Return true.
		 */
		if (string1[ i ] == '\0') {
			return(1);
		}

		/* If we find a mismatch, return false. Otherwise just keep going. */
		if (string1[i] != string2[i]) {
			return(0);
		}

		++i;
	}
}

int main(void) {

	if (begins("fodo", "foobar")) {
		printf("they match!\n");
	} else {
		printf("no match.\n");
	}

	return(0);
}

