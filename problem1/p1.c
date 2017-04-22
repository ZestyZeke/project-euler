/*
 * p1.c
 *
 * Zeke Reyna
 *
 * This function finds the sum all multiples of 3 and 5 below 1000.
 */

#include <stdio.h>
#include <stdlib.h>

#define BOUND 1000

int main( int argc, char **argv )
{
	int sum;
	int i;

	sum = 0;
	for( i = 0; i < BOUND; i++ ) {
		if( i % 3 == 0 || i % 5 == 0 )
			sum += i;
	}

	printf( "the sum of all multiples of 3 and 5 below 1000" );
	printf( " is %d\n" , sum );

	return 0;
}
