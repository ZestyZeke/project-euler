/*
 * p5.c
 *
 * Problem 5:
 * What is the smallest positive number that is evenly divisible by all of
 * the numbers from 1 to 20?
 */

#include <stdio.h>
#include <stdlib.h>
#define			TEST		10
#define			DEFAULT		20
#define			REDUNDANT	0

void generate_divisors(int *divisors, int bound)
{
	for (int i = 1; i <= bound; i++)
		divisors[i - 1] = i;

	int num, pos_factor;
	for (int i = bound - 1; i >= 0; i--) {
		num = divisors[i];
		if (num == REDUNDANT)
			continue;
		for (int j = i - 1; j >= 0; j--) {
			pos_factor = divisors[j];
			if (pos_factor == REDUNDANT)
				continue;
			if (num % pos_factor == 0)
				divisors[j] = REDUNDANT;
		}
	}
}

long long find_first_divisible_num(int *divisors, int bound)
{
	long long num = (long long) bound;
	int found = 0;
	int divisor;

	while (!found && num++) {
		found = 1;
		for (int i = 0; i < bound; i++) {
			divisor = divisors[i];
			if (divisor == REDUNDANT)
				continue;
			if (num % divisor != 0) {
				found = 0;
				break;
			}
		}
	}

	return num;
}

int main(int argc, char **argv)
{
	int bound;
	(argc == 2) ? (bound = atoi(argv[1])) : (bound = DEFAULT);

	int divisors[bound];
	generate_divisors(divisors, bound);

	long long num = find_first_divisible_num(divisors, bound);

	printf("\nThe smallest positive number that is divisible by all of");
	printf(" the numbers from 1 to %d is: %llu\n\n", bound, num);

	return 0;
}
