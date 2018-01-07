/*
 * p10.c
 *
 * Zeke Reyna
 *
 * Problem 10:
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // link with -lm

#define		BOUND_DEF	2000000

void generate_list(int primes[], int size)
{
	for (int i = 0; i < size; i++)
		primes[i] = 0;
}

/*
 * Upper bound for primes, generated according to Pierre Dusart's
 * thesis on the Prime Number Theorem, works for n >= 60184
 */
int generate_bound(int n)
{
	if (n < 60184)
		return n;
	return (int) (((double)n) / (log(n) - 1.1));
}

void sieve(int primes[], int size, int bound)
{
	int num;	// integers to possibly add
	int i;		// for iterating primes[]
	int pos;	// "position in primes[]"
	int isPrime;

	for (num = 2, pos = 0; pos < size && num < bound; num++) {
		isPrime = 1;
		for (i = 0; primes[i] != 0 && isPrime; i++) {
			if (num % primes[i] == 0)
				isPrime = 0;
		}
		if (isPrime) {
			primes[pos] = num;
			pos++;
		}
	}
}

unsigned long long sum_primes(int primes[], int size)
{
	unsigned long long sum = 0;
	for (int i = 0; primes[i] != 0 && i < size; i++)
		sum += primes[i];
	return sum;
}

int main(int argc, char **argv)
{
	int n;
	int size;
	unsigned long long sum;

	(argc == 2) ? (n = atoi(argv[1])) : (n = BOUND_DEF);

	size = 0;
	size = generate_bound(n);
	int primes[size];
	generate_list(primes, size);
	sieve(primes, size, n);
	sum = sum_primes(primes, size);

	printf("\nThe sum of the primes below %d", n);
	printf(" is %llu\n\n", sum);
	return 0;
}
