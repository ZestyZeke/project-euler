/*
 * p5.c
 *
 * Zeke Reyna
 *
 * Q: What is the smallest number that is evenly divisible by all of the numbers
 * from 1 to 20?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // don't forget to link math library

#define BOUND 10

int main( int argc, char **argv )
{
	int i;
	int num;
	int bound;
	int isDivis;

	if( argc == 2 )
		bound = atoi( argv[1] );
	else
		bound = BOUND;

	int div_list[ BOUND ];
	for( i = 1; i <= BOUND; i++ )
		div_list[i - 1] = i;

	num = 3; //semi random starting point
	isDivis = 0;
	while( !isDivis ) {
		num++;
		isDivis = 1;
		for( i = 0; i < BOUND; i++ ) {
			if( num % div_list[i] != 0 )
				isDivis = 0;
		}
	}

	printf( "\nThe smallest number that is evenly divisible by all of " );
	printf( "the numbers from 1 to %d is %d\n\n", BOUND, num );
	return 0;
}
