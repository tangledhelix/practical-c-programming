/**********************************************************************
 * Design an airline reservation data structure that contains the
 * following data:
 *
 * - Flight number
 * - Originating airport code (3 characters)
 * - Destination airport code (3 characters)
 * - Starting time
 * - Arrival time
 *
 * Write a program that lists all the planes that leave from two airports
 * specified by the user.
 **********************************************************************/

#include <stdio.h>
#include <string.h>

struct reservation_struct {
	int flight_number;
	char departure_airport[ 4 ];
	char arrival_airport[ 4 ];
	char departure_time[ 16 ];
	char arrival_time[ 16 ];
};

int main( void ) {

	char airport1[ 100 ];       /* keyboard input */
	char airport2[ 100 ];       /* end airport */

	int i;                      /* loop counter */

	struct reservation_struct reservations[ 20 ] = {
		{ 3269, "CLE", "BOS", "20110120090436", "20110120090436" },
		{ 4189, "BOS", "CLE", "20110120090436", "20110120090436" },
		{ 603,  "JFK", "ORD", "20110120090436", "20110120090436" },
		{ 900,  "CLE", "MDW", "20110120090436", "20110120090436" },
		{ 1337, "BOS", "ORD", "20110120090436", "20110120090436" },
		{ 9027, "CLE", "MSP", "20110120090436", "20110120090436" },
		{ 6167, "CLE", "SJC", "20110120090436", "20110120090436" },
		{ 8887, "CLE", "SEA", "20110120090436", "20110120090436" },
		{ 1230, "CLE", "NUQ", "20110120090436", "20110120090436" },
		{ 9723, "BOS", "ANK", "20110120090436", "20110120090436" },
		{ 723, "MSP", "JUN", "20110120090436", "20110120090436" }
	};

	/* result:
	 * Found flight 3269: CLE -> BOS
	 * Found flight 4189: BOS -> CLE
	 * Found flight 900: CLE -> MDW
	 * Found flight 1337: BOS -> ORD
	 * Found flight 9027: CLE -> MSP
	 * Found flight 6167: CLE -> SJC
	 * Found flight 8887: CLE -> SEA
	 * Found flight 1230: CLE -> NUQ
	 * Found flight 9723: BOS -> ANK
	 */

	printf( "Enter airport code: " );
	fgets( airport1, sizeof( airport1 ), stdin );
	airport1[ strlen( airport1 ) -1 ] = '\0';       /* trim newline */

	printf( "Enter another airport code: " );
	fgets( airport2, sizeof( airport2 ), stdin );
	airport2[ strlen( airport2 ) -1 ] = '\0';       /* trim newline */

	printf( "You entered: %s, %s\n\n", airport1, airport2 );

	/* Look for all airports leaving from either of those */
	for ( i = 0; i < sizeof( reservations ); ++i ) {
		if ( ( strncmp( reservations[ i ].departure_airport, airport1, sizeof( airport1 ) ) == 0 ) ||
			( strncmp( reservations[ i ].departure_airport, airport2, sizeof( airport2 ) ) == 0 ) ) {
					printf( "Found flight %d: %s -> %s\n", reservations[ i ].flight_number,
							reservations[ i ].departure_airport, reservations[ i ].arrival_airport );
		}
	}

	return( 0 );
}

