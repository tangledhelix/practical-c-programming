/**********************************************************************
 * Write a program that converts numbers to words. For example,
 * 859 results in "eight nine five."
 **********************************************************************/

#include <stdio.h>
#include <string.h>

char line[ 100 ];           /* line of input from keyboard */

int digit;                  /* digit we're looking at currently */
char word[ 50 ];            /* english word for digit */
int i;                      /* index into an array */

int main() {

	printf( "Enter a number: " );
	fgets( line, sizeof( line ), stdin );

	for ( i = 0; ; ++i ) {
		if ( line[ i ] == '\n' ) {
			printf( "\n" );
			return( 0 );
		}
		switch ( line[ i ] ) {
			case '0':
				strcpy( word, "zero" );
				break;
			case '1':
				strcpy( word, "one" );
				break;
			case '2':
				strcpy( word, "two" );
				break;
			case '3':
				strcpy( word, "three" );
				break;
			case '4':
				strcpy( word, "four" );
				break;
			case '5':
				strcpy( word, "five" );
				break;
			case '6':
				strcpy( word, "six" );
				break;
			case '7':
				strcpy( word, "seven" );
				break;
			case '8':
				strcpy( word, "eight" );
				break;
			case '9':
				strcpy( word, "nine" );
				break;
			default:
				strcpy( word, "UNKNOWN" );
				break;
		}
		printf( "%s ", word );
	}
}

