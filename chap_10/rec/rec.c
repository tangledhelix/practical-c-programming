/**********************************************************************
 * This tell us that we have an undefined variable number,
 * but our only variable name is counter.
 **********************************************************************/

#include <stdio.h>
/* problem is here, there's a space between the macro name and
 * its parenthesized parameter list
 */
/*#define RECIPROCAL (number) (1.0 / (number))*/
#define RECIPROCAL(number) (1.0 / (number))

int main() {
	float counter;          /* Counter for our table */

	for ( counter = 0.0; counter < 10.0; counter += 1.0 ) {
		printf( "1/%f = %f\n", counter, RECIPROCAL(counter));
	}

	return( 0 );
}
