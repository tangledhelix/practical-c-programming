/**********************************************************************
 * Write a program that reads a character and prints out whether or
 * not it is a vowel or a consonant. Enter '0' to quit.
 **********************************************************************/

#include <stdio.h>

char line[ 100 ];               /* keyboard input */
char character;                 /* the character in question */

int main() {

	while ( 1 ) {
		printf( "Enter a letter (0 to quit): " );
		fgets( line, sizeof( line ), stdin );
		sscanf( line, "%c", &character );

		switch ( character ) {
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				printf( "Definitely a vowel.\n" );
				break;

			case 'b':
			case 'B':
			case 'c':
			case 'C':
			case 'd':
			case 'D':
			case 'f':
			case 'F':
			case 'g':
			case 'G':
			case 'h':
			case 'H':
			case 'j':
			case 'J':
			case 'k':
			case 'K':
			case 'l':
			case 'L':
			case 'm':
			case 'M':
			case 'n':
			case 'N':
			case 'p':
			case 'P':
			case 'q':
			case 'Q':
			case 'r':
			case 'R':
			case 's':
			case 'S':
			case 't':
			case 'T':
			case 'v':
			case 'V':
			case 'w':
			case 'W':
			case 'x':
			case 'X':
			case 'z':
			case 'Z':
				printf( "That's a consonant if I ever saw one.\n" );
				break;

			case 'y':
			case 'Y':
				printf( "Definitely maybe a vowel. Sort of. Sometimes.\n" );
				break;

			case '0':
				printf( "Goodbye.\n" );
				return( 0 );

			default:
				printf( "Can you read? I said a LETTER. Try '0' to quit.\n" );
				break;

		}
	}

}

