/**********************************************************************
 * Why does this generate the answer 47 instead of the expected 144?
 **********************************************************************/

/**********************************************************************
 * Because it evaluates to 7 + 5 * 7 + 5. The operator precedence
 * rules fall out like this:
 *      7 + ( 5 * 7 ) + 5
 *      7 + 35 + 5
 *      47
 *
 * Can be solved by putting parens around the right-hand side of
 * the ALL_PARTS #define, or surrounding each ALL_PARTS with parens
 * in the printf().
 **********************************************************************/

#include <stdio.h>

#define FIRST_PART      7
#define LAST_PART       5
#define ALL_PARTS       FIRST_PART + LAST_PART

int main() {
	printf( "The square of all the parts is %d\n",
			ALL_PARTS * ALL_PARTS );
	return( 0 );
}

