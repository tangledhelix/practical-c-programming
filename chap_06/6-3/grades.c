/**********************************************************************
 * A professor generates letter grades using this table.
 *
 * % right      grade
 * -----------  -----
 *  0 - 60       F
 *  61 - 70      D
 *  71 - 80      C
 *  81 - 90      B
 *  91 - 100     A
 *
 * last digit  modifier
 * ----------  --------
 *  1-3         -
 *  4-7         <blank>
 *  8-0         +
 *
 * For example, 81=B-, 94=A, and 68=D+. An F is only an F. There is
 * no F+ or F-.
 *
 * Given a numeric grade, print the letter grade and any modifier.
 **********************************************************************/

#include <stdio.h>

int percent_right;      /* percentage of correct answers */
char grade;             /* letter grade */
char modifier;          /* modifier (+ or -) */
char line[ 100 ];       /* line of keyboard input */

int main() {
	printf( "Enter the percentage correct: " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%d", &percent_right );

	modifier = ' ';   /* empty space by default (no modifier) */

	if ( percent_right > 100 ) {
		printf( "Error: out of bounds\n" );
		return( 1 );
	} else if ( percent_right < 0 ) {
		printf( "Error: out of bounds\n" );
		return( 1 );
	} else if ( percent_right >= 91 ) {
		grade = 'A';
		if ( percent_right >= 98 ) {
			modifier = '+';
		} else if ( percent_right <= 93 ) {
			modifier = '-';
		}
	} else if ( percent_right >= 81 ) {
		grade = 'B';
		if ( percent_right >= 88 ) {
			modifier = '+';
		} else if ( percent_right <= 83 ) {
			modifier = '-';
		}
	} else if ( percent_right >= 71 ) {
		grade = 'C';
		if ( percent_right >= 78 ) {
			modifier = '+';
		} else if ( percent_right <= 73 ) {
			modifier = '-';
		}
	} else if ( percent_right >= 61 ) {
		grade = 'D';
		if ( percent_right >= 68 ) {
			modifier = '+';
		} else if ( percent_right <= 63 ) {
			modifier = '-';
		}
	} else {
		grade = 'F';
	}

	printf( "The grade is %c%c\n", grade, modifier );

	return( 0 );
}
