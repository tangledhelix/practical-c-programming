/**********************************************************************
 * The number 85 is pronounced "eighty-five," not "eight five."
 * Modify the previous program to handle the numbers 0 through 100
 * so that all numbers come out as we really say them. For example,
 * 13 would be "thirteen" and 100 would be "one hundred."
 **********************************************************************/

/**********************************************************************
 * Previously:
 * Write a program that converts numbers to words. For example,
 * 859 results in "eight nine five."
 **********************************************************************/

/**********************************************************************
 * This version uses a more concise method to determine the initial
 * and post-hyphen text for the majority of cases.
 **********************************************************************/

#include <stdio.h>
#include <string.h>

int number;                 /* number we're looking at currently */

int tens_place;             /* a place to store the tens value */
int last_digit;             /* a place to stash the last digit */

int main() {

	for (number = 0; number <= 100; ++number) {

		/* numbers below 20 are all custom */
		if (number < 20) {
			switch (number) {
				case 0:
					printf("zero");
					break;
				case 1:
					printf("one");
					break;
				case 2:
					printf("two");
					break;
				case 3:
					printf("three");
					break;
				case 4:
					printf("four");
					break;
				case 5:
					printf("five");
					break;
				case 6:
					printf("six");
					break;
				case 7:
					printf("seven");
					break;
				case 8:
					printf("eight");
					break;
				case 9:
					printf("nine");
					break;
				case 10:
					printf("ten");
					break;
				case 11:
					printf("eleven");
					break;
				case 12:
					printf("twelve");
					break;
				case 13:
					printf("thirteen");
					break;
				case 14:
					printf("fourteen");
					break;
				case 15:
					printf("fifteen");
					break;
				case 16:
					printf("sixteen");
					break;
				case 17:
					printf("seventeen");
					break;
				case 18:
					printf("eighteen");
					break;
				case 19:
					printf("nineteen");
					break;
			}

		} else if (number == 100) {
			printf("one hundred!");

		} else {
			tens_place = number / 10;       /* calculate the tens place */
			last_digit = number % 10;       /* calculate a remainder (ones place) */

			switch (tens_place) {
				case 2:
					printf("twenty");
					break;
				case 3:
					printf("thirty");
					break;
				case 4:
					printf("forty");
					break;
				case 5:
					printf("fifty");
					break;
				case 6:
					printf("sixty");
					break;
				case 7:
					printf("seventy");
					break;
				case 8:
					printf("eighty");
					break;
				case 9:
					printf("ninety");
					break;
			}

			switch (last_digit) {
				case 1:
					printf("-one");
					break;
				case 2:
					printf("-two");
					break;
				case 3:
					printf("-three");
					break;
				case 4:
					printf("-four");
					break;
				case 5:
					printf("-five");
					break;
				case 6:
					printf("-six");
					break;
				case 7:
					printf("-seven");
					break;
				case 8:
					printf("-eight");
					break;
				case 9:
					printf("-nine");
					break;
			}
		}

		printf("\n");
	}

	return(0);
}

