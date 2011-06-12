/**********************************************************************
 * This generates a warning that counter is used before it is set.
 * This warning is a surprise to us because the for loop should
 * set it. We also get a very strange warning, "null effect,"
 * for line 11.
 **********************************************************************/

/* warning, spacing is VERY important */

#include <stdio.h>

/* problem 1: there should not be an = sign here */
#define MAX =10

int main() {
	int counter;

	/* problem 2: this evals to 'counter = =10' */
	/* oddly enough, this is different from the example's complaint,
	 * which i assume was supposed to expand to 'counter ==10',
	 * which would trigger a 'used before set' error that i did not
	 * encounter.
	 */
	for ( counter =MAX; counter > 0; --counter )
		printf( "Hi there\n" );

	return( 0 );
}

