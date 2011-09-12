/**********************************************************************
 * A leap year is any year divisible by 4, unless the year is
 * divisible by 100, but not 400. Write a program to tell if a
 * year is a leap year.
 **********************************************************************/

#include <stdio.h>

char line[100];             /* a line of input */
int year;                   /* a year */
int leap_year = 0;          /* if zero, not a leap year, otherwise yes */

int main() {
	printf("Enter a year: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &year);

	/* Any year divisible by 4 is a leap year... */
	if (year % 4 == 0) {
		leap_year = 1;

		/* Unless the year is divisible by 100, but not 400 */
		if (year % 100 == 0) {
			if (year % 400 != 0) {
				leap_year = 0;
			}
		}

	}

	if (leap_year == 1) {
		printf("%d is a leap year.\n", year);
	} else {
		printf("%d is not a leap year.\n", year);
	}

	return(0);
}

