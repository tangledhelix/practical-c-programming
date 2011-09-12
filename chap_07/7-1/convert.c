/**********************************************************************
 * Convert
 *
 * Converts Imperial units to Metric
 *
 * Available conversions:
 *
 * - miles to kilometers
 * - gallons to liters
 * - inches to centimeters
 * - feet to meters
 **********************************************************************/

#include <stdio.h>

const float MILE_TO_KILOMETER  = 1.6093;
const float GALLON_TO_LITER    = 3.7854;
const float INCH_TO_CENTIMETER = 2.54;
const float FOOT_TO_METER      = 0.3048;

char line[100];             /* line of input from user */
char unit_type;             /* the type of unit we are given */
float unit_value;           /* the value we are given */
float result;               /* result of the conversion */

int main() {
	while (1) {

		/* throw out the values from our last run */
		unit_type = '\0';
		unit_value = 0.0;

		/* get input from the user */
		printf("\n(m:miles g:gallons i:inches f:feet q:quit)\n");
		printf("Enter the unit type and value: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c %f", &unit_type, &unit_value);

		/* provide an exit route */
		if ((unit_type == 'q') || (unit_type == 'Q')) {
			printf("Goodbye!\n");
			return(0);
		}

		/* determine conversion type and perform the calculation */
		if (unit_type == 'm') {
			result = unit_value * MILE_TO_KILOMETER;
			printf("%f miles = %f kilometers\n", unit_value, result);
		} else if (unit_type == 'g') {
			result = unit_value * GALLON_TO_LITER;
			printf("%f gallons = %f liters\n", unit_value, result);
		} else if (unit_type == 'i') {
			result = unit_value * INCH_TO_CENTIMETER;
			printf("%f inches = %f centimeters\n", unit_value, result);
		} else if (unit_type == 'f') {
			result = unit_value * FOOT_TO_METER;
			printf("%f feet = %f meters\n", unit_value, result);
		} else {
			printf("Error: unknown conversion\n");
			continue;
		}
	}
}

