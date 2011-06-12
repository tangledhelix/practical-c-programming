/**********************************************************************
 * Design a structure to store time and date. Write a function to find
 * the difference between two times in minutes.
 **********************************************************************/

#include <stdio.h>

#define MINUTES_PER_HOUR (60)
#define MINUTES_PER_DAY (MINUTES_PER_HOUR * 24)

/*
 * define map of months to days
 * leading 0 is for index 0 (unused).
 *
 * trailing 0 is so the array is not 13 elements.
 * thank my superstitious Sicilian grandmother.
 */

int month_map[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0 };

/* structure to hold a date/time */
struct datetime {
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

/* prototypes */

int is_leap_year( int year );
int get_delta( int start_month, int start_day, int end_month, int end_day, int year );
int day_delta( int start, int end, int month );
int minutes_delta( int start_hour, int start_minute, int end_hour, int end_minute );

/* here we go. */

int main( void ) {

	/* a place to store the total delta when calculated */
	int total;

	/* our start and end dates */

	struct datetime start;
	start.year = 2006;
	start.month = 12;
	start.day = 29;
	start.hour = 20;
	start.minute = 3;

	struct datetime end;
	end.year = 2009;
	end.month = 1;
	end.day = 8;
	end.hour = 9;
	end.minute = 20;

	/* to store temporary values */
	int result;
	int this_year;

	/* calculate the delta. */

	if ( end.year - start.year > 1 ) {
		/* there are intervening whole years, let's add them in */

		this_year = end.year - 1;
		while ( this_year > start.year ) {

			total += 365;

			if ( is_leap_year( this_year ) ) {
				/* add one for leap year */
				++total;
			}

			--this_year;
		}

		/* calculate start year date through end of the year */
		result = get_delta( start.month, start.day, 12, 31, start.year );
		total += result;

		/* calculate jan 1st through end year date */
		result = get_delta( 1, 1, end.month, end.day, end.year );
		total += result;

		/* convert days to minutes */
		total *= MINUTES_PER_DAY;

		/* calculate spare minutes in start day */
		total += minutes_delta( start.hour, start.minute, 23, 59 );

		/* calculate spare minutes in end day */
		total += minutes_delta( 0, 0, end.hour, end.minute );

	} else if ( end.year - start.year == 1 ) {
		/* adjacent years */

		/* calculate start year date through end of the year */
		result = get_delta( start.month, start.day, 12, 31, start.year );
		total += result;

		/* calculate jan 1st through end year date */
		result = get_delta( 1, 1, end.month, end.day, end.year );
		total += result;

		/* convert days to minutes */
		total *= MINUTES_PER_DAY;

		/* calculate spare minutes in start day */
		total += minutes_delta( start.hour, start.minute, 23, 59 );

		/* calculate spare minutes in end day */
		total += minutes_delta( 0, 0, end.hour, end.minute );

	} else if ( end.year == start.year ) {
		/* same year */

		result = get_delta( start.month, start.day, end.month, end.day, start.year );
		total += result;

		/* convert days to minutes */
		total *= MINUTES_PER_DAY;

		/* calculate spare minutes in start day */
		total += minutes_delta( start.hour, start.minute, 23, 59 );

		/* calculate spare minutes in end day */
		total += minutes_delta( 0, 0, end.hour, end.minute );

	} else {
		printf( "ERROR: undefined problem.\n" );
		printf( "       perhaps end.date is earlier than start.date?\n" );
	}

	printf( "\n** DELTA: %d minutes\n", total );
	return( 0 );
}

/**********************************************************************
 * is_leap_year( year )
 *
 * Determines whether a given year is a leap year (mathematically).
 *
 * Returns true (1) if so, false (0) if not.
 **********************************************************************/

int is_leap_year( int year ) {

	int flag = 0;       /* boolean flag */

	/* Any year divisible by 4 is a leap year... */
	if ( year % 4 == 0 ) {
		flag = 1;

		/* Unless the year is divisible by 100, but not 400 */
		if ( year % 100 == 0 ) {
			if ( year % 400 != 0 ) {
				flag = 0;
			}
		}
	}

	return flag;
}

/**********************************************************************
 * get_delta( start_month, start_day, end_month, end_day, year )
 *
 * Get the delta between two dates within a given year.
 *
 * Returns int delta value.
 **********************************************************************/

int get_delta( int start_month, int start_day, int end_month, int end_day, int year ) {

	int delta = 0;

	int result;
	int this_month;

	if ( end_month - start_month > 1 ) {
		/* we know there are whole months in the middle */

		this_month = end_month - 1;
		while ( this_month  > start_month ) {

			delta += month_map[ this_month ];

			if ( is_leap_year( year ) && ( this_month == 2 ) ) {
				++delta;

			}

			--this_month;
		}

		/* calculate days in starting month (inclusive) */
		result = ( month_map[ start_month ] - start_day + 1 );
		delta += result;

		/* ending month day no. is fit to simply add to the total */
		delta += end_day;

	} else if ( end_month - start_month == 1 ) {
		/* the end and start months are adjacent */

		/* calculate days in starting month (inclusive) */
		result = ( month_map[ start_month ] - start_day + 1 );
		delta += result;

		/* ending month day no. is fit to simply add to the total */
		delta += end_day;

	} else if ( end_month == start_month ) {
		/* it is the same month */

		result = day_delta( start_day, end_day, start_month );
		delta = result;

	} else {
		printf( "ERROR: Should never reach this code\n" );
	}

	return delta;
}

/**********************************************************************
 * day_delta - get a count between two days (within a month)
 *
 * Returns int number of days.
 **********************************************************************/

int day_delta( int start, int end, int month ) {

	int delta;

	/* make sure we're not out of bounds */
	if ( end > month_map[ month ] ) {
		printf( "ERROR: out of bounds (only %d days this month)\n", month_map[ month ] );
	}

	/* get the number of days in between by subtracting */
	/* add one back to make it inclusive of starting day */
	delta = end - start + 1;

	return delta;
}

/**********************************************************************
 * minutes_delta - get the number of minutes between start hour/minute
 * and end hour/minute. This is used to calculate the minutes on the
 * start and end days, which are not full days.
 **********************************************************************/

int minutes_delta( int start_hour, int start_minute, int end_hour, int end_minute ) {

	int delta;
	int this_hour;
	int result;

	delta = 0;

	printf( "DEBUG: minutes_delta(%d,%d,%d,%d)\n",
			start_hour, start_minute, end_hour, end_minute );

	/* make sure we're not out of bounds */
	if ( ( start_hour < 0 ) || ( start_hour > 23 ) ) {
		printf( "ERROR: %d out of bounds (hour must be 0-23)\n", start_hour );
	}
	if ( ( end_hour < 0 ) || ( end_hour > 23 ) ) {
		printf( "ERROR: %d out of bounds (hour must be 0-23)\n", end_hour );
	}
	if ( ( start_minute < 0 ) || ( start_minute > 59 ) ) {
		printf( "ERROR: %d out of bounds (minute must be 0-59)\n", start_minute );
	}
	if ( ( end_minute < 0 ) || ( end_minute > 59 ) ) {
		printf( "ERROR: %d out of bounds (minute must be 0-59)\n", end_minute );
	}

	printf( "DEBUG: start=%d:%d end=%d:%d\n",
			start_hour, start_minute, end_hour, end_minute );

	if ( end_hour - start_hour > 1 ) {
		/* there are whole hours in the middle, calculate them in */
		printf( "DEBUG: filling whole hours\n" );

		this_hour = end_hour - 1;
		while ( this_hour > start_hour ) {
			printf( "DEBUG: added 60 mins for hour %d\n", this_hour );
			delta += MINUTES_PER_HOUR;
			--this_hour;
		}

		/* calculate minutes in starting hour (inclusive) */
		printf( "DEBUG: adding %d for starting hour\n", MINUTES_PER_HOUR - start_minute );
		delta += ( MINUTES_PER_HOUR - start_minute );

		/* calculate minutes in ending hour, easy. */
		printf( "DEBUG: adding %d for ending hour\n", end_minute + 1 );
		delta += ( end_minute + 1 );        /* +1 for minute 0 */

	} else if ( end_hour - start_hour == 1 ) {
		/* these are adjacent hours */
		printf( "DEBUG: adjacent hours\n" );

		/* calculate minutes in starting hour (inclusive) */
		printf( "DEBUG: adding %d for starting hour\n", MINUTES_PER_HOUR - start_minute );
		delta += ( MINUTES_PER_HOUR - start_minute );

		/* calculate minutes in ending hour, easy. */
		printf( "DEBUG: adding %d for ending hour\n", end_minute );
		delta += end_minute;

	} else if ( end_hour == start_hour ) {
		/* same hour, just calculate minutes */
		printf( "DEBUG: within same hour\n" );
		printf( "DEBUG: adding %d minutes\n", end_minute - start_minute + 1 );
		delta = end_minute - start_minute + 1;

	} else {
		printf( "ERROR: shouldn't get here. is end_hour < start_hour?\n" );
	}

	printf( "DEBUG: minutes_delta() returns %d\n", delta );
	return delta;

}

