/**********************************************************************
 * Design a structure to hold the data for a mailing list. Write a
 * function to print out the data.
 **********************************************************************/

#include <stdio.h>
#include <string.h>

struct mail_list {
	char name[ 50 ];            /* name of recipient */
	int address;                /* address (house number) */
	char street1[ 50 ];         /* street name */
	char street2[ 50 ];         /* additional street address info, apt # etc */
	char city[ 50 ];            /* city, town, village */
	char state[ 3 ];            /* two-letter postal code for state */
	int zip;                    /* postal zip code */
};

void print_list( struct mail_list *mlist );

int main( void ) {

	/* a list that can have up to 100 entries */
	struct mail_list list[ 100 ];

	/* populate our list with some data */

	strcpy( list[ 0 ].name, "John Doe" );
	list[ 0 ].address = 123;
	strcpy( list[ 0 ].street1, "Mockingbird Lane" );
	strcpy( list[ 0 ].city, "Dallas" );
	strcpy( list[ 0 ].state, "TX" );
	list[ 0 ].zip = 44132;

	strcpy( list[ 1 ].name, "James Dean" );
	list[ 1 ].address = 457;
	strcpy( list[ 1 ].street1, "Cool Luke Drive" );
	strcpy( list[ 1 ].city, "Philadelphia" );
	strcpy( list[ 1 ].state, "PA" );
	list[ 1 ].zip = 98137;

	strcpy( list[ 2 ].name, "James Beard" );
	list[ 2 ].address = 229;
	strcpy( list[ 2 ].street1, "Peppermill Court" );
	strcpy( list[ 2 ].street2, "Mail Stop 3A2" );
	strcpy( list[ 2 ].city, "Los Angeles" );
	strcpy( list[ 2 ].state, "CA" );
	list[ 2 ].zip = 97149;

	print_list( list );

	return( 0 );
}

void print_list( struct mail_list *mlist ) {

	int i;          /* loop counter */

	printf( "MAILING LIST\n\n" );

	for ( i = 0; i < sizeof( mlist ); ++i ) {
		if ( strlen( mlist[ i ].name ) == 0 ) {
			continue;
		}

		printf( "%s\n", mlist[ i ].name );
		printf( "%d %s\n", mlist[ i ].address, mlist[ i ].street1 );
		if ( strlen( mlist[ i ].street2 ) ) {
			printf( "%s\n", mlist[ i ].street2 );
		}
		printf( "%s, %s  %d\n\n", mlist[ i ].city, mlist[ i ].state, mlist[ i ].zip );
	}

}

