/*
 * p3.c
 *
 * Zeke Reyna
 *
 * Problem 3:
 * What is the largest prime factor of the number 600851475143
 *
 * note: this solution depends on using the sqrt(n) as the upper bound which
 * is incorrect. this doesn't solve for all numers exactly, so beware
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define		TEST		13195
#define		DEFAULT		600851475143
#define		END_OF_LIST	-2

typedef unsigned long long ull;

long check_if_pf(const long *prime_facts, const long i, long *j)
{
	for (*j = 1;
	     prime_facts[*j] != END_OF_LIST && i % prime_facts[*j] != 0;
	     (*j)++)
		;

	return prime_facts[*j];
}

void find_prime_facts(long *prime_facts, const long bound, const ull num)
{
	long i, j;
	for (i = 2; i <= bound; i++) {
		if (num % i == 0) {
			long poss_pf = check_if_pf(prime_facts, i, &j);

			if (poss_pf == END_OF_LIST) {
				prime_facts[j]	 = i;
				prime_facts[++j] = END_OF_LIST;
			}
		}
	}
}

long get_end(long *prime_facts)
{
	long i;
	for (i = 0; prime_facts[i] != END_OF_LIST; i++)
		;
	return prime_facts[--i];
}

int main(int argc, char **argv)
{
	ull num;
	(argc == 2) ? (num = (ull) atoi(argv[1])) : (num = DEFAULT);

	long bound = (long) sqrt(num) + 1;
	long prime_factors[bound];
	prime_factors[0] = 1;
	prime_factors[1] = END_OF_LIST;

	find_prime_facts(prime_factors, bound, num);
	ull largest_prime = (ull) get_end(prime_factors);
	if (largest_prime == 1)
		largest_prime = num;

	printf("\nThe largest prime factor");
	printf(" of %llu is %llu\n\n", num, largest_prime);

	return 0;
}
