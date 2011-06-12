
#include <stdio.h>

float data[ 5 ];    /* data to average and total */
float total;        /* the total of the data items */
float average;      /* average of the items */

int main() {
	data[ 0 ] = 34.0;
	data[ 1 ] = 27.0;
	data[ 2 ] = 45.0;
	data[ 3 ] = 82.0;
	data[ 4 ] = 22.0;

	total = data[ 0 ] + data[ 1 ] + data[ 2 ] + data[ 3 ] + data[ 4 ];
	average = total / 5.0;
	printf( "Total %f Average %f\n", total, average );

	return( 0 );
}
