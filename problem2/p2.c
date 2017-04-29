/*
 * fib.c
 *
 * Zeke Reyna
 *
 * This is a simple function that sums fibonacci numbers
 * under a certain bound.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOUND 10

int main( int argc, char **argv )
{

	int first;
	int second;
	int third;
	int sum;
	int bound;

	(argc == 2) ? (bound = atoi(argv[1]) ) : (bound = BOUND);

	first = 1;
	second = 1;
	third = 0;
	sum = 0;

	while( third < bound ) {
		if( second % 2 == 0 )
			sum += second;
		//sum += second;
		third = first + second;
		first = second;
		second = third;
	}

	printf( "\nthe sum of even valued fibonacci terms under %d ", bound );
	printf( "is %d\n\n", sum );
	return 0;
}