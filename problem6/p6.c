/*
 * p6.c
 *
 * Zeke Reyna
 *
 * Find the Difference between the sum of the squares of the first n natural
 * numbers and the square of the sum of the first n natural numbers.
 */

#include <stdio.h>
#include <stdlib.h>

#define BOUND 10

int sqr( int x )
{
	return x*x;
}

int triangle( int n )
{
	return ( sqr( n ) + n ) / 2;
}

int sum_of_squares( int n )
{
	return n * (n + 1) * (2 * n + 1) / 6;
}

int main( int argc, char **argv )
{
	/*
	 * sum of first n natural numbers is the triangular number
	 * (n^2+n)/2
	 *
	 * sum of squares of n natural numbers is
	 * n(n+1)(2n+1)/6
	 */

	int bound;
	int answer;
	(argc == 2) ? (bound = atoi(argv[1])) : (bound = BOUND);

	answer = sum_of_squares( bound ) - sqr( triangle( bound ) );

	if( answer < 0 )
		answer = -1 * answer;

	printf( "\nThe Difference between the Sum of the Squares and the" );
	printf( " square of the sum of the first %d natural numbers", bound );
	printf( " is %d\n\n", answer );
	return 0;
}
