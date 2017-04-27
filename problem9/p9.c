/*
 * p9.c
 *
 * Zeke Reyna
 *
 * There exists one pythagorean triplet such that a + b + c = 100.
 * Find the product a*b*c.
 *
 * For reference: 3^2 + 4^2 = 5^2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LIMIT 12
#define SQR(x) ((x)*(x))

int find_c( int a, int b )
{
	int c = (int) sqrt( SQR(a) + SQR(b) );

	if( SQR(c) != SQR(a) + SQR(b) )
		c = -1;

	return c;
}

int main( int argc, char **argv )
{
	int sum_limit;
	int i, j, c;
	int product;

	(argc == 2) ? (sum_limit = atoi( argv[1] )) : (sum_limit = LIMIT );

	product= -1;
	// note, sum_limit being the bound worked in this case, but
	// might not be the best choice
	for( i = 1; i < sum_limit; i++ ) {
		for( j = 1; j < sum_limit; j++ ) {

			c = find_c( i, j );

			if( c == -1 )
				continue;
			else if( i + j + c == sum_limit ) {
				product = i * j * c;
				goto found;
			} else
				continue;
		}
	}

found:
	//printf( " i is %d, j is %d, c is %d\n", i, j, c );
	printf("\nThe product of the pythagorean triplets that sum to " );
	printf( "%d is %d\n\n", sum_limit, product);

	return 0;
}
