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
 * Given a numeric grade, print the letter.
 **********************************************************************/

#include <stdio.h>

float percent_right;    /* percentage of correct answers */
char grade;             /* letter grade */
char line[ 100 ];       /* line of keyboard input */

int main() {
	printf( "Enter the percentage correct: " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%f", &percent_right );

	if ( percent_right >= 91.0 ) {
		grade = 'A';
	} else if ( percent_right >= 81.0 ) {
		grade = 'B';
	} else if ( percent_right >= 71.0 ) {
		grade = 'C';
	} else if ( percent_right >= 61.0 ) {
		grade = 'D';
	} else {
		grade = 'F';
	}

	printf( "The grade is %c\n", grade );

	return( 0 );
}
