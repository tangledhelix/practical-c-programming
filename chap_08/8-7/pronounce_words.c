/**********************************************************************
 * The number 85 is pronounced "eighty-five," not "eight five."
 * Modify the previous program to handle the numbers 0 through 100
 * so that all numbers come out as we really say them. For example,
 * 13 would be "thirteen" and 100 would be "one hundred."
 **********************************************************************/

/**********************************************************************
 * Previously:
 * Write a program that converts numbers to words. For example,
 * 859 results in "eight nine five."
 **********************************************************************/

#include <stdio.h>
#include <string.h>

int number;                 /* number we're looking at currently */

int main() {

	for ( number = 0; number < 100; ++number ) {

		/* numbers below 20 are all custom */
		if ( number < 20 ) {
			switch ( number ) {
				case 0:
					printf( "zero" );
					break;
				case 1:
					printf( "one" );
					break;
				case 2:
					printf( "two" );
					break;
				case 3:
					printf( "three" );
					break;
				case 4:
					printf( "four" );
					break;
				case 5:
					printf( "five" );
					break;
				case 6:
					printf( "six" );
					break;
				case 7:
					printf( "seven" );
					break;
				case 8:
					printf( "eight" );
					break;
				case 9:
					printf( "nine" );
					break;
				case 10:
					printf( "ten" );
					break;
				case 11:
					printf( "eleven" );
					break;
				case 12:
					printf( "twelve" );
					break;
				case 13:
					printf( "thirteen" );
					break;
				case 14:
					printf( "fourteen" );
					break;
				case 15:
					printf( "fifteen" );
					break;
				case 16:
					printf( "sixteen" );
					break;
				case 17:
					printf( "seventeen" );
					break;
				case 18:
					printf( "eighteen" );
					break;
				case 19:
					printf( "nineteen" );
					break;
			}

		} else if ( ( number >= 20 ) && ( number <= 29 ) ) {
			printf( "twenty" );
			switch ( number ) {
				case 21:
					printf( "-one" );
					break;
				case 22:
					printf( "-two" );
					break;
				case 23:
					printf( "-three" );
					break;
				case 24:
					printf( "-four" );
					break;
				case 25:
					printf( "-five" );
					break;
				case 26:
					printf( "-six" );
					break;
				case 27:
					printf( "-seven" );
					break;
				case 28:
					printf( "-eight" );
					break;
				case 29:
					printf( "-nine" );
					break;
			}
		} else if ( ( number >= 30 ) && ( number <= 39 ) ) {
			printf( "thirty" );
			switch ( number ) {
				case 31:
					printf( "-one" );
					break;
				case 32:
					printf( "-two" );
					break;
				case 33:
					printf( "-three" );
					break;
				case 34:
					printf( "-four" );
					break;
				case 35:
					printf( "-five" );
					break;
				case 36:
					printf( "-six" );
					break;
				case 37:
					printf( "-seven" );
					break;
				case 38:
					printf( "-eight" );
					break;
				case 39:
					printf( "-nine" );
					break;
			}
		} else if ( ( number >= 40 ) && ( number <= 49 ) ) {
			printf( "forty" );
			switch ( number ) {
				case 41:
					printf( "-one" );
					break;
				case 42:
					printf( "-two" );
					break;
				case 43:
					printf( "-three" );
					break;
				case 44:
					printf( "-four" );
					break;
				case 45:
					printf( "-five" );
					break;
				case 46:
					printf( "-six" );
					break;
				case 47:
					printf( "-seven" );
					break;
				case 48:
					printf( "-eight" );
					break;
				case 49:
					printf( "-nine" );
					break;
			}
			
		} else if ( ( number >= 50 ) && ( number <= 59 ) ) {
			printf( "fifty" );
			switch ( number ) {
				case 51:
					printf( "-one" );
					break;
				case 52:
					printf( "-two" );
					break;
				case 53:
					printf( "-three" );
					break;
				case 54:
					printf( "-four" );
					break;
				case 55:
					printf( "-five" );
					break;
				case 56:
					printf( "-six" );
					break;
				case 57:
					printf( "-seven" );
					break;
				case 58:
					printf( "-eight" );
					break;
				case 59:
					printf( "-nine" );
					break;
			}
		
		} else if ( ( number >= 60 ) && ( number <= 69 ) ) {
			printf( "sixty" );
			switch ( number ) {
				case 61:
					printf( "-one" );
					break;
				case 62:
					printf( "-two" );
					break;
				case 63:
					printf( "-three" );
					break;
				case 64:
					printf( "-four" );
					break;
				case 65:
					printf( "-five" );
					break;
				case 66:
					printf( "-six" );
					break;
				case 67:
					printf( "-seven" );
					break;
				case 68:
					printf( "-eight" );
					break;
				case 69:
					printf( "-nine" );
					break;
			}

		} else if ( ( number >= 70 ) && ( number <= 79 ) ) {
			printf( "seventy" );
			switch ( number ) {
				case 71:
					printf( "-one" );
					break;
				case 72:
					printf( "-two" );
					break;
				case 73:
					printf( "-three" );
					break;
				case 74:
					printf( "-four" );
					break;
				case 75:
					printf( "-five" );
					break;
				case 76:
					printf( "-six" );
					break;
				case 77:
					printf( "-seven" );
					break;
				case 78:
					printf( "-eight" );
					break;
				case 79:
					printf( "-nine" );
					break;
			}

		} else if ( ( number >= 80 ) && ( number <= 89 ) ) {
			printf( "eighty" );
			switch ( number ) {
				case 81:
					printf( "-one" );
					break;
				case 82:
					printf( "-two" );
					break;
				case 83:
					printf( "-three" );
					break;
				case 84:
					printf( "-four" );
					break;
				case 85:
					printf( "-five" );
					break;
				case 86:
					printf( "-six" );
					break;
				case 87:
					printf( "-seven" );
					break;
				case 88:
					printf( "-eight" );
					break;
				case 89:
					printf( "-nine" );
					break;
			}

		} else if ( ( number >= 90 ) && ( number <= 99 ) ) {
			printf( "ninety" );
			switch ( number ) {
				case 91:
					printf( "-one" );
					break;
				case 92:
					printf( "-two" );
					break;
				case 93:
					printf( "-three" );
					break;
				case 94:
					printf( "-four" );
					break;
				case 95:
					printf( "-five" );
					break;
				case 96:
					printf( "-six" );
					break;
				case 97:
					printf( "-seven" );
					break;
				case 98:
					printf( "-eight" );
					break;
				case 99:
					printf( "-nine" );
					break;
			}

		} else if ( number == 100 ) {
			printf( "one hundred!" );
		}

		printf( "\n" );
	}

	return( 0 );
}

