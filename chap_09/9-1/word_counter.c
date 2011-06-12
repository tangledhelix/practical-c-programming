/**********************************************************************
 * Write a procedure that counts the number of words in a string.
 * (Your documentation should describe exactly how you define a word.)
 * Write a program to test your new procedure.
 **********************************************************************/

#include <stdio.h>

/**********************************************************************
 * count_words( string phrase )
 *
 * Count the words in a phrase. Returns integer, number of words
 * in the phrase.
 *
 * Definition of a word: any contiguous chunk between spaces.
 *
 * Flaws: uses whitespace to count words. Trailing space, two
 * contiguous spaces, etc., will fool it.
 **********************************************************************/

int count_words( char phrase[] ) {
	static int str_idx = 0;             /* index into the string */
	static int word_count = 0;          /* count of seen words */

	while ( phrase[ str_idx ] != '\0' ) {

		if ( ( phrase[ str_idx ] == ' ' ) || ( phrase[ str_idx ] == '\n' ) ) {
			++word_count;
		}

		++str_idx;
		count_words( phrase );
	}

	return word_count;
}

int main( void ) {
	int result;
	char line[ 100 ];           /* line of keyboard input */

	printf( "Enter a string: " );
	fgets( line, sizeof( line ), stdin );

	result = count_words( line );
	printf( "Found %d words\n", result );

	return( 0 );
}

