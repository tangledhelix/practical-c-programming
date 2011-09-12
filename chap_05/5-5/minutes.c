/**********************************************************************
 * Write a program that takes hours and minutes as input, and then
 * outputs the total number of minutes.
 *
 * 1 hour 30 minutes = 90 minutes
 **********************************************************************/

#include <stdio.h>

int hours;          /* given number of hours */
int minutes;        /* given number of minutes */
int total_minutes;  /* total number of minutes (computed) */

const int MINPERHOUR = 60;      /* number of minutes in 1 hour */

char line[50];      /* line of input from keyboard */

int main() {
	printf("Enter hours: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &hours);

	printf("Enter minutes: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &minutes);

	total_minutes = minutes + (hours * MINPERHOUR);

	printf("Total: %d minutes.\n", total_minutes);

	return(0);
}

