/**********************************************************************
 * Write a macro is_digit that returns TRUE if its argument is a
 * decimal digit.
 *
 * Write a second macro is_hex that returns true if its argument is a
 * hex digit (0-9, A-F, a-f). The second macro should reference the first.
 **********************************************************************/

#include <stdio.h>

#define is_digit(x) ( ((x)=='0') || ((x)=='1') || ((x)=='2') || ((x)=='3') \
	|| ((x)=='4') || ((x)=='5') || ((x)=='6') || ((x)=='7') \
	|| ((x)=='8') || ((x)=='9') )

#define is_hex(x) ( ((x)=='a') || ((x)=='b') || ((x)=='c') || ((x)=='d') \
	|| ((x)=='e') || ((x)=='f') || ((x)=='A') || ((x)=='B') || ((x)=='C') \
	|| ((x)=='D') || ((x)=='E') || ((x)=='F') || is_digit(x) )

int main() {
	if ( is_hex('9') ) {
		printf( "ok\n" );
	} else {
		printf( "wtf\n" );
	}
	if ( is_hex('f') ) {
		printf( "ok\n" );
	} else {
		printf( "wtf\n" );
	}
	if ( is_hex('2') ) {
		printf( "ok\n" );
	} else {
		printf( "wtf\n" );
	}
	if ( is_hex('|') ) {
		printf( "wtf\n" );
	} else {
		printf( "ok\n" );
	}
	if ( is_hex('t') ) {
		printf( "wtf\n" );
	} else {
		printf( "ok\n" );
	}
	if ( is_hex('D') ) {
		printf( "ok\n" );
	} else {
		printf( "wtf\n" );
	}
	return( 0 );
}

