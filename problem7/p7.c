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

int generate_lower( int n )
{
	double term1, term2;
	term1 = n * log( n );
	term2 = n * ( log( log( n ) ) - 1 );
	return (int) (term1 + term2 + 1); // bounds are exclusive
}

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

	int lowerbound, upperbound;
	int i;
	int n, prime;

	(argc == 2) ? (n = atoi(argv[1])) : (n = BOUND);

	lowerbound = generate_lower( n );
	upperbound = generate_upper( n );

	prime = -1;
	for( i = lowerbound; i <= upperbound; i++ ) {
		if( isPrime( i ) ) {
			prime = i; // an extra variable is unnecessary
			break;
		}
	}

	printf( "\n bounds are %d and %d\n", lowerbound, upperbound );
	printf( "\nThe %dth prime number is %d\n\n", n, prime );
	return 0;
}
