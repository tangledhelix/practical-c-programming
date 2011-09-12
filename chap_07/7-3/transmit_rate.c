/**********************************************************************
 * A serial transmission line can transmit 960 characters each second.
 * Write a program that will calculate the time required to send a file,
 * given the file's size. Try the program on a 400MB (419,430,400 byte)
 * file. Use appropriate units. (A 400MB file takes days.)
 **********************************************************************/

#include <stdio.h>

/*#define DEBUG*/
#undef DEBUG

const int CPS = 960;            /* characters per second (transmit rate) */

const int MINUTE = 60;              /* length of one minute, in seconds */
const int HOUR   = 60 * 60;         /* length of one hour, in seconds */
const int DAY    = 60 * 60 * 24;    /* length of one day, in seconds */

int total_seconds;              /* total seconds for the transmission */

int days;                       /* how many days it took */
int hours;                      /* how many hours it took */
int minutes;                    /* how many minutes it took */
int seconds;                    /* how many seconds it took */

char line[ 100 ];               /* line of input from keyboard */

int filesize;                   /* file size in bytes */

int main() {

	printf("Enter file size in bytes: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &filesize);

#ifdef DEBUG
	printf("DEBUG:main(): filesize is %d\n", filesize);
#endif

	total_seconds = filesize / CPS;

#ifdef DEBUG
	printf("DEBUG:main(): total_seconds is %d\n", total_seconds);
#endif

	/* calculate whole days */
	days = total_seconds / DAY;
	/* calculate remainder after whole days are consumed */
	total_seconds = total_seconds % DAY;

#ifdef DEBUG
	printf("DEBUG:main(): days is %d\n", days);
	printf("DEBUG:main(): remainder is %d\n", total_seconds);
#endif

	/* calculate whole hours */
	hours = total_seconds / HOUR;
	/* calculate remainder after whole hours are consumed */
	total_seconds = total_seconds % HOUR;

#ifdef DEBUG
	printf("DEBUG:main(): hours is %d\n", hours);
	printf("DEBUG:main(): remainder is %d\n", total_seconds);
#endif

	/* calculate whole minutes */
	minutes = total_seconds / MINUTE;
	/* calculate remainder after whole minutes are consumed */
	seconds = total_seconds % MINUTE;

#ifdef DEBUG
	printf("DEBUG:main(): minutes is %d\n", minutes);
	printf("DEBUG:main(): seconds is %d\n", seconds);
#endif

	printf("%d days, %d hours, %d minutes, %d seconds\n",
			days, hours, minutes, seconds);

	return(0);
}

