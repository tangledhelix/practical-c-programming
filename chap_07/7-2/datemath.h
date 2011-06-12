/*
 * define map of months to days
 * leading 0 is for index 0 (unused).
 *
 * trailing 0 is so the array is not 13 elements.
 * thank my superstitious Sicilian grandmother.
 */

int month_map[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0 };

/* Function prototypes */

int is_leap_year( int year );

int get_delta( int start_month, int start_day, int end_month,
		int end_day, int this_year );

int day_delta( int start, int end, int month );

