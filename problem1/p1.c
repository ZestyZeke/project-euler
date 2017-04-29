/*
 * p1.c
 *
 * Zeke Reyna
 *
 * This function finds the sum all multiples of 3 and 5 below 1000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOUND 10

int main( int argc, char **argv )
{
	int sum;
	int i;
	int bound;

	(argc == 2) ? (bound = atoi( argv[1] )) : (bound = BOUND);

	sum = 0;
	for( i = 0; i < bound; i++ ) {
		if( i % 3 == 0 || i % 5 == 0 )
			sum += i;
	}

	printf( "\nthe sum of all multiples of 3 and 5 below 1000" );
	printf( " is %d\n\n" , sum );

	return 0;
}
