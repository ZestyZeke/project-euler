/*
 * p8.c
 *
 * Zeke Reyna
 *
 * Reads in a large text file that represents an int, then finds the adjacent
 * digits that form the largest product.
 *
 * In this specific case, the goal is a 100 digit number, and to find the
 * 13 adjacent digits that form the largest product.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096
#define ADJACENT 4

long long find_product( char *buf_pos, int adj )
{
	int i;
	long long product;
	product = 1;

	for( i = 0; i < adj; i++ ) {
		product *= buf_pos[ i ] - '0'; //convert char to int
	}

	return product;
}

int main( int argc, char **argv )
{
	char buffer[ BUF_SIZE ];
	FILE *fp;
	int i;
	int adj;
	long long largest_product;
	long long curr_product;

	(argc == 2) ? (adj = atoi(argv[1])) : (adj = ADJACENT);

	fp = fopen( "num.txt", "r" );
	fgets( buffer, BUF_SIZE, fp );
	fclose( fp );

	largest_product = -1;
	for( i = 0; buffer[ i + adj ] != '\0'; i++ ) {

		curr_product = find_product( &buffer[i], adj );

		if( curr_product > largest_product )
			largest_product = curr_product;
	}

	printf( "\nThe largest product of the %d adjacent digits are", adj );
	printf( " %lld\n\n", largest_product );
	return 0;
}
