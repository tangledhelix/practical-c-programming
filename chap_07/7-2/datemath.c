/**********************************************************************
 * DateMath - calculate the delta between two dates.
 *
 * Dan Lowe, 11 Jan 2011
 **********************************************************************/

/*#define DEBUG*/
#undef DEBUG

#include <stdio.h>
#include "datemath.h"

char line[100];             /* line of input from keyboard */

int start_month;            /* month from starting date */
int start_day;              /* day from starting date */
int start_year;             /* year from starting date */

int end_month;              /* month from ending date */
int end_day;                /* day from ending date */
int end_year;               /* year from ending date */

int delta;                  /* for keeping state inside some funcs */
int result;                 /* for collecting a result */

int this_year;              /* for doing year math */
int this_month;             /* for doing month math */

int total;                  /* where to store our total delta for output */

int main(void) {

	printf("Enter starting date (mm/dd/yyyy): ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d/%d/%d", &start_month, &start_day, &start_year);

#ifdef DEBUG
	printf("DEBUG:main(): date is %d/%d/%d\n",
			start_month, start_day, start_year);

	if (is_leap_year(start_year)) {
		printf("DEBUG:main(): this is a leap year.\n");
	}
#endif

	printf("Enter ending date (mm/dd/yyyy): ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d/%d/%d", &end_month, &end_day, &end_year);

#ifdef DEBUG
	printf("DEBUG:main(): date is %d/%d/%d\n", end_month, end_day, end_year);

	if (is_leap_year(end_year)) {
		printf("DEBUG:main(): this is a leap year.\n");
	}
#endif

	if (end_year - start_year > 1) {
		/* there are intervening whole years, let's add them in */

		this_year = end_year - 1;
		while (this_year > start_year) {

#ifdef DEBUG
			printf("DEBUG:main(): found intervening year %d, added 365\n",
					this_year);
#endif

			total += 365;

			if (is_leap_year(this_year)) {
				/* add one for leap year */
				++total;

#ifdef DEBUG
				printf("DEBUG:main(): added 1 for leap year\n");
#endif

			}

			--this_year;
		}

		/* calculate start year date through end of the year */
		result = get_delta(start_month, start_day, 12, 31, start_year);
		total += result;

#ifdef DEBUG
		printf("DEBUG:main(): got delta %d for %d/%d - 12/31 in %d\n",
				result, start_month, start_day, start_year);
#endif

		/* calculate jan 1st through end year date */
		result = get_delta(1, 1, end_month, end_day, end_year);
		total += result;

#ifdef DEBUG
		printf("DEBUG:main(): got delta %d for 1/1 - %d/%d in %d\n",
				result, end_month, end_day, end_year);
#endif

	} else if (end_year - start_year == 1) {
		/* adjacent years */

#ifdef DEBUG
		printf("DEBUG:main(): adjacent years\n");
#endif

		/* calculate start year date through end of the year */
		result = get_delta(start_month, start_day, 12, 31, start_year);
		total += result;

#ifdef DEBUG
		printf("DEBUG:main(): got delta %d for %d/%d - 12/31 in %d\n",
				result, start_month, start_day, start_year);
#endif

		/* calculate jan 1st through end year date */
		result = get_delta(1, 1, end_month, end_day, end_year);
		total += result;

#ifdef DEBUG
		printf("DEBUG:main(): got delta %d for 1/1 - %d/%d in %d\n",
				result, end_month, end_day, end_year);
#endif

	} else if (end_year == start_year) {
		/* same year */

#ifdef DEBUG
		printf("DEBUG:main(): dates fall within same year\n");
#endif

		result = get_delta(start_month, start_day,
				end_month, end_day, start_year);
		total += result;

#ifdef DEBUG
		printf("DEBUG:main(): got delta %d for %d/%d - %d/%d in %d\n",
				result, start_month, start_day,
				end_month, end_day, start_year);
#endif

	} else {
		printf("ERROR: undefined problem.\n");
		printf("       perhaps end_date is earlier than start_date?\n");
	}

	printf("\n** DELTA: %d days\n", total);

	return(0);
}

/**********************************************************************
 * is_leap_year(year)
 *
 * Determines whether a given year is a leap year (mathematically).
 *
 * Returns true (1) if so, false (0) if not.
 **********************************************************************/

int is_leap_year(int year) {

	int flag = 0;       /* boolean flag */

	/* Any year divisible by 4 is a leap year... */
	if (year % 4 == 0) {
		flag = 1;

		/* Unless the year is divisible by 100, but not 400 */
		if (year % 100 == 0) {
			if (year % 400 != 0) {
				flag = 0;
			}
		}
	}

#ifdef DEBUG
	if (flag) {
		printf("DEBUG:is_leap_year(): YES\n");
	}
#endif

	return flag;
}

/**********************************************************************
 * get_delta(start_month, start_day, end_month, end_day, year)
 *
 * Get the delta between two dates within a given year.
 *
 * Returns int delta value.
 **********************************************************************/

int get_delta(int start_month, int start_day, int end_month, int end_day,
		int year) {

	delta = 0;

	if (end_month - start_month > 1) {
		/* we know there are whole months in the middle */

#ifdef DEBUG
		printf("DEBUG:get_delta(): found whole months in middle of range\n");
#endif

		this_month = end_month - 1;
		while (this_month  > start_month) {

#ifdef DEBUG
			printf("DEBUG:get_delta(): found intervening month %d\n",
					this_month);
#endif

			delta += month_map[this_month];

#ifdef DEBUG
			printf("DEBUG:get_delta(): added %d to delta\n",
					month_map[this_month]);
#endif

			if (is_leap_year(year) && (this_month == 2)) {
				++delta;

#ifdef DEBUG
				printf("DEBUG:get_delta(): added 1 to delta for leap year\n");
#endif
			}

			--this_month;
		}

		/* calculate days in starting month (inclusive) */
		result = (month_map[start_month] - start_day + 1);
		delta += result;

#ifdef DEBUG
		printf("DEBUG:get_delta(): added %d for month %d\n",
				result, start_month);
#endif

		/* ending month day no. is fit to simply add to the total */
		delta += end_day;

#ifdef DEBUG
		printf("DEBUG:get_delta(): added %d for month %d\n",
				end_day, end_month);
#endif

	} else if (end_month - start_month == 1) {
		/* the end and start months are adjacent */

#ifdef DEBUG
		printf("DEBUG:get_delta(): adjacent months\n");
#endif

		/* calculate days in starting month (inclusive) */
		result = (month_map[start_month] - start_day + 1);
		delta += result;

#ifdef DEBUG
		printf("DEBUG:get_delta(): got %d delta for month %d",
				result, start_month);
#endif

		/* ending month day no. is fit to simply add to the total */
		delta += end_day;

#ifdef DEBUG
		printf("DEBUG:get_delta(): got %d delta for month %d",
				end_day, end_month);
#endif

	} else if (end_month == start_month) {
		/* it is the same month */

#ifdef DEBUG
		printf("DEBUG:get_delta(): within one month\n");
#endif

		result = day_delta(start_day, end_day, start_month);
		delta = result;

#ifdef DEBUG
		printf("DEBUG:get_delta(): got %d delta for month %d\n",
				result, start_month);
#endif

	} else {
		printf("ERROR: Should never reach this code\n");
	}

#ifdef DEBUG
	printf("DEBUG:get_delta(): returning %d\n", delta);
#endif

	return delta;
}

/**********************************************************************
 * day_delta - get a count between two days (within a month)
 *
 * Returns int number of days.
 **********************************************************************/

int day_delta(int start, int end, int month) {

	/* make sure we're not out of bounds */
	if (end > month_map[month]) {
		printf("ERROR: out of bounds (only %d days this month)\n",
				month_map[month]);
	}

	/* get the number of days in between by subtracting */
	/* add one back to make it inclusive of starting day */
	delta = end - start + 1;

#ifdef DEBUG
	printf("DEBUG:day_delta(): returning delta %d\n", delta);
#endif

	return delta;
}

