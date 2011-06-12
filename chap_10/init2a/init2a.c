int data[ 10 ];             /* some data */
int twice[ 10 ];            /* twice some data */

int main( void ) {
	int index;          /* index into the data */

	for ( index = 0; index < 10; ++index ) {
		data[ index ] = index;
		twice[ index ] = index * 2;
	}

	return( 0 );
}

