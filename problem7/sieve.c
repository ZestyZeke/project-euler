/*
 * p7.c
 *
 * Zeke Reyna
 *
 * A simple file to find the nth prime
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // link with -lm in Makefile

#define BOUND 7

int generate_upper( int n )
{
	double term1, term2;
	term1 = n * log( n );
	term2 = n * ( log( log( n ) ) );
	return (int) (term1 + term2); // bounds are exclusive
}

// 1 if prime, 0 if not
int isPrime( int i )
{
	int j;
	int bound;
	int retval;


	bound = (int) sqrt( i ) + 1;
	retval = 1;
	for( j = 2; j < bound; j++ ) {
		if( i % j == 0 ) {
			retval = 0;
			break;
		}
	}
	return retval;
}

int main( int argc, char **argv )
{
	/*
	 * nth prime number will be between the bounds
	 * n ln(n) + n(ln(ln(n))-1) and
	 * n ln(n) + n(ln(ln(n))) for n >= 6
	 */

	int upperbound;
	int i;
	int n, prime;

	(argc == 2) ? (n = atoi(argv[1])) : (n = BOUND);

	upperbound = generate_upper( n );
	int num_list[ upperbound ];
	int size;

	// populate list
	for( i = 0; i < upperbound; i++ ) {
		num_list[i] = i + 1;
	}
	size = upperbound;

	// might have to put add or remove options... might be easier
	// to use a linked list of sorts.
	// need to make num_list into a true list,
	// with a list_del functionality
	for( i = 0; i < (int) sqrt( upperbound ); i++ ) {
		// go through num_list checking if things are divisible by i
		// remove from list and continue
		for( j = 0; j < size; j++ ) {
			if( j % i == 0 ) {
				list_del( &num_list, &size );
			}
		}
	}
	// now spot n should have the (n+1)th prime
	prime = num_list[ n - 1];

	printf( "\n bounds are %d and %d\n", lowerbound, upperbound );
	printf( "\nThe %dth prime number is %d\n\n", n, prime );
	return 0;
}
