/*
 * p1.c
 *
 * Zeke Reyna
 *
 * Problem 1: Find the sum of the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>
#include <stdlib.h>
#define			DEFAULT		1000

int main(int argc, char **argv)
{
	unsigned long long sum = 0;
	int i;
	int bound;

	(argc == 2) ? (bound = atoi(argv[1])) : (bound = DEFAULT);

	for (i = 1; i < bound; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	printf("\nThe sum of the multiples of 3 or 5 below %d are:", bound);
	printf(" %llu\n\n", sum);
	return 0;
}
