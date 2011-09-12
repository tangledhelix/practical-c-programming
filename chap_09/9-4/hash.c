/**********************************************************************
 * Write a function that takes a character array and returns a primitive
 * hash code by adding up the value of each character in the array.
 **********************************************************************/

#include <stdio.h>

int array_hash(char chars[]) {
	int i;              /* index into an array */
	int hash = 0;       /* hash code */

	for (i = 0; i < sizeof(chars); ++i) {
		hash += chars[i];
	}

	return(hash);
}

int main(void) {
	char char_array[] = { 'A', 'b', 'N', 'o' };

	printf("Result: %d\n", array_hash(char_array));

	return(0);
}
