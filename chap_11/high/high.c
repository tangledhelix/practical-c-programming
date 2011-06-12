/**********************************************************************
 * The HIGH_SPEED flag works, but DIRECT_CONNECT does not. Why?
 **********************************************************************/

/**********************************************************************
 * Well it does work for me. Perhaps the Mac assigns more than 8 bits
 * to a char, to accomodate unicode or something else?
 *
 * I assume the original answer to this problem was that you can't
 * shift left by 8 bits because then you've shifted out the entire
 * char and you're left with 0x0. But if a char is really 16 bits
 * or some other allocation > 8 bits, then this would work on the
 * Mac as written.
 **********************************************************************/

#include <stdio.h>

const int HIGH_SPEED = ( 1 << 7 );      /* modem is running fast */

/* we are using a hardwired connection */
const int DIRECT_CONNECT = ( 1 << 8 );

char flags = 0;         /* start with nothing */

int main() {
	flags |= HIGH_SPEED;            /* we're running fast */
	flags |= DIRECT_CONNECT;        /* because we're wired together */

	if ( ( flags & HIGH_SPEED ) != 0 ) {
		printf( "High speed set\n" );
	}

	if ( ( flags & DIRECT_CONNECT ) != 0 ) {
		printf( "Direct connect set\n" );
	}

	return( 0 );
}

