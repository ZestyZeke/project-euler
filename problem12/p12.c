/*
 * p12.c
 *
 * Zeke Reyna
 *
 * A simple file to find the first triangular number that has over five
 * hundred divisors.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIVIS 5

/*
 * sum divisors = (p1 + 1)(p2 + 1)...
 * product of exponents of prime factors + 1
 */
int find_num_factors( int num )
{
	int i;
	int num_factors, power;
	num_factors = 1; // or should be 1? or 2?

	for( i = 2; i < (int) sqrt( num ); i++ ) {
		power = 0;

		while( num % i == 0 ) {
			num /= i;
			power++;
		}
		num_factors *= (power + 1);
	}

	if( num > 1 )
		num_factors = num_factors * 2;

	return num_factors;
}

int main( int argc, char **argv )
{
	int divis;
	int i, tri;
	int num_divis;
	int num_looking_for;

	(argc == 2) ? (divis = atoi( argv[1] )) : (divis = DIVIS);

	i = 1;
	for( tri = 1; (tri = (i * i + i) / 2); i++ ) {

		num_divis = find_num_factors( tri );
		if( num_divis > divis ) {
			num_looking_for = tri;
			break;
		}
	}

	printf( "\nThe first triangular number that has greater than " );
	printf( "%d divisors is %d\n\n", divis, num_looking_for );

	return 0;
}
