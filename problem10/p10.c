/*
 * p10.c
 *
 * Zeke Reyna
 *
 * Sums all the primes under a bound
 */

#include "p10.h"

void generate_nums( int nums[], int size )
{
	int i;
	for( i = 0; i < size; i++ ) {
		nums[i] = i + 2;
	}
}

void sieve_nums( int nums[], int size )
{
	int i, j;
	int temp_prime;

	for( i = 0; i < size; i++ ) {

		temp_prime = nums[i];
		if( temp_prime == NOT_PRIME )
			continue;

		for( j = i + 1; j < size; j++ ) {
			if( nums[j] % temp_prime == 0 )
				nums[j] = NOT_PRIME;
		}
	}
}

unsigned long long sum_nums( int nums[], int size )
{
	unsigned long long sum;
	int i;

	sum = 0;
	for( i = 0; i < size; i++ ) {
		if( nums[i] != NOT_PRIME )
			sum += nums[i];
	}

	return sum;
}

int main( int argc, char **argv )
{
	int n;
	unsigned long long sum;

	(argc == 2) ? (n = atoi(argv[1])) : (n = BOUND_DEF);

	int nums[ n - 2];
	generate_nums( nums, n - 2 );
	sieve_nums( nums, n - 2 );
	sum = sum_nums( nums, n - 2 );

	printf("\nThe sum of the primes below %d", n );
	printf(" is %llu\n\n", sum );

	return 0;
}
