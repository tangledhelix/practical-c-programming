/**********************************************************************
 * Write a procedure that counts the number of words in a string.
 * (Your documentation should describe exactly how you define a word.)
 * Write a program to test your new procedure.
 **********************************************************************/

/* This version uses a better algorithm for word detection. */

#include <stdio.h>

/**********************************************************************
 * count_words( string phrase )
 *
 * Count the words in a phrase. Returns integer, number of words
 * in the phrase.
 *
 * Definition of a word: any contiguous chunk between spaces.
 *
 * Flaws:
 *
 * Uses whitespace to count words. Thus, a contiguous
 * chunk of non-word characters surrounded by whitespace will
 * fool it (meaning e.g. ",.!#" would count as a word if there
 * were two spaces, or a string boundary, on the ends).
 *
 * Tab is not checked, so it would also count as a word. Also,
 * two words separated by tab would probably count as one word
 * because no spaces are in between. I ignored that case because
 * this is just a learning exercise, not production code.
 **********************************************************************/

int count_words( char phrase[] ) {
	int i = 0;                  /* index into the string */
	int word_count = 0;         /* count of seen words */

	while ( 1 ) {

		if ( phrase[ i ] == '\0' ) {
			/* end of the string, get out of the loop */
			break;
		}

		if ( phrase[ i ] == '\n' ) {
			/* newline is not a word character */
			++i;
			continue;
		}

		/*
		 * "begin word" detection:
		 * if current char is not a space
		 *     if this is position 0 assume it's a new word
		 *     otherwise assume it is if the prev char is a space
		 */
		if ( phrase[ i ] != ' ' ) {
			if ( i == 0 ) {
				++word_count;
			} else if ( phrase[ i - 1 ] == ' ' ) {
				++word_count;
			}
		}

		++i;
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

