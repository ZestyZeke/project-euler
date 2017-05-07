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

// list of nums to sieve through
void generate_nums( int nums[], int size )
{
	int i;
	for( i = 2; i < size + 2; i++ )
		nums[i - 2] = i;
}

int sieve( int nums[], int nums_size, int n )
{
	int i, j;
	int temp_n, temp_prime;

	temp_n = 1;
	for( i = 0; i < nums_size && temp_n <= n; i++ ) {

		if( nums[i] == -1 )
			continue;

		temp_prime = nums[ i ];
		for( j = i + 1; j < nums_size; j++ ) {
			if( nums[j] % temp_prime == 0 )
				nums[j] = -1; // essentially NULL
		}
		temp_n++;
	}
	return nums[--i];
}

int main( int argc, char **argv )
{
	int n;
	int upperbound;
	int nth_prime;

	(argc == 2) ? (n = atoi(argv[1])) : (n = BOUND);

	upperbound = generate_upper( n );

	// can generate a ton of numbers and seive through them,
	// by placing -1's in place of nums that are composite

	int nums[ upperbound ];
	generate_nums( nums, upperbound );

	nth_prime = sieve( nums, upperbound, n );

	printf( "\nThe %dth prime number is %d\n\n", n, nth_prime );

	return 0;
}
