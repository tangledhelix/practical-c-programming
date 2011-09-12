/**********************************************************************
 * Write a program that, given the number of hours an employee
 * worked and the hourly wage, computes the employee's weekly pay.
 * Count any hours over 40 as time and a half.
 **********************************************************************/

#include <stdio.h>

char line[100];             /* line of keyboard input */
float hours;                /* hours worked */
float wage;                 /* wage (dollars per hour) */
float overtime = 0.0;       /* hours of overtime */
float paycheck;             /* how much we paid out for the work */

int main() {
	printf("Enter hours worked: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &hours);

	printf("Enter wage: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &wage);

	if (hours > 40.0) {
		overtime = (hours - 40.0) * 1.5;
		hours = 40.0;
		paycheck = (hours * wage) + (overtime * wage);
	} else {
		paycheck = hours * wage;
	}

	printf("Paycheck: $%0.2f\n", paycheck);

	return(0);
}

