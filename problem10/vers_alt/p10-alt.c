/*
 * p10-alt.c
 *
 * Zeke Reyna
 *
 * An Alt solution, using the Prime
 * Number Theorem to generate the size
 * of the array. This could incredibly speed
 * up the iteration during the sieve.
 */

#include <stdio.h>
#include <math.h>

#define BOUND 2000000
#define TEST_BOUND 60184

void generate_list( int primes[], int size )
{
	int i;
	for( i = 0; i < size; i++ )
		primes[i] = 0;
}

int generate_bound( int n )
{
	return (int) ((double)n / (log(n) - 1.1));
}

void sieve( int primes[], int size )
{
	int num; // integers to possibly add
	int i; // for iterating primes[]
	int pos; // "position in primes[]"
	int isPrime;

	for( num = 2, pos = 0; pos < size && num < size; num++ ) {

		isPrime = 1;
		for( i = 0; primes[i] != 0 && isPrime; i++ ) {

			if( num % primes[i] == 0 )
				isPrime = 0;
		}

		if( isPrime ) {
			primes[pos] = num;
			pos++;
		}
	}

}

unsigned long long sum_primes( int primes[], int size )
{
	unsigned long long sum;
	int i;

	sum = 0;
	for( i = 0; primes[i] != 0; i++ )
		sum += primes[i];

	return sum;
}

int main( int argc, char **argv )
{
	int n;
	int size;
	unsigned long long sum;

	(argc == 2) ? (n = BOUND) : (n = TEST_BOUND);

	size = 0;
	size = generate_bound( n );
	//int primes[ size ] = { 0 }; //initialize with all vals as 0
	int primes[size];
	generate_list( primes, size );
	sieve( primes, size );
	sum = sum_primes( primes, size );

	printf("\nThe sum of the primes below %d", n );
	printf(" is %llu\n\n", sum );

	return 0;
}
