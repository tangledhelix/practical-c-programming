/**********************************************************************
 * Design an airline reservation data structure that contains the
 * following data:
 *
 * - Flight number
 * - Originating airport code (3 characters)
 * - Destination airport code (3 characters)
 * - Starting time
 * - Arrival time
 **********************************************************************/

#include <stdio.h>

struct reservation_struct {
	int flight_number;
	char departure_airport[4];
	char arrival_airport[4];
	int departure_time;
	int arrival_time;
};

int main(void) {
	return(0);
}

