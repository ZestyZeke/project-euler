/*
 * p3.c
 *
 * Zeke Reyna
 *
 * A simple function that finds the largest prime factor of a number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM 600851475143

int main()
{
	int largest_prime;
	unsigned long long num = NUM;
	long bound = (long) sqrt( num );
	int prime_factors[ bound ];
	int i, j;

	largest_prime = 1;
	prime_factors[0] = 1;
	prime_factors[1] = -1; //-1 used as null terminator

	for( i = 2; i < bound; i++ ) {
		if( num % i == 0 ) {
			for( j = 1; i % prime_factors[j] != 0; j++ )
				;

			if( prime_factors[j] == -1 ) {
				prime_factors[j] = i;
				prime_factors[++j] = -1;
			}
		}
	}

	for( i = 0; prime_factors[i] != -1; i++ )
		;

	largest_prime = prime_factors[--i];

	printf( "\nThe largest prime factor" );
	printf( " of %llu is %d\n\n", num, largest_prime );
	return 0;
}
