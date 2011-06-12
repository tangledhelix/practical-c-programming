/**********************************************************************
 * Write a macro is_digit that returns TRUE if its argument is a
 * decimal digit.
 **********************************************************************/

#include <stdio.h>

#define is_digit(x) ( ((x)=='0') || ((x)=='1') || ((x)=='2') || ((x)=='3') \
	|| ((x)=='4') || ((x)=='5') || ((x)=='6') || ((x)=='7') \
	|| ((x)=='8') || ((x)=='9') )

int main() {
	if ( is_digit('9') ) {
		printf( "ok\n" );
	} else {
		printf( "wtf\n" );
	}
	if ( is_digit('f') ) {
		printf( "wtf\n" );
	} else {
		printf( "ok\n" );
	}
	if ( is_digit('2') ) {
		printf( "ok\n" );
	} else {
		printf( "wtf\n" );
	}
	if ( is_digit('|') ) {
		printf( "wtf\n" );
	} else {
		printf( "ok\n" );
	}
	return( 0 );
}

