/*
 * p14.c
 *
 * Zeke Reyna
 *
 * Finds the largest Collatz sequence under a given bound.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT 10

unsigned long long search_for_chains(int bound)
{
	unsigned long long i;
	unsigned long long largest_num, largest_seq;
	unsigned long long temp_num, temp_seq;

	largest_num = 0;
	largest_seq = 0;
	for (i = 2; i < bound; i++) {

		temp_seq = 0;
		for (temp_num = i; temp_num != 1; temp_seq++) {

			if (temp_num % 2 == 0)
				temp_num = temp_num / 2;
			else
				temp_num = 3 * temp_num + 1;
		}

		if (temp_seq > largest_seq) {
			largest_seq = temp_seq;
			largest_num = i;
		}
	}
	return largest_num;
}

int main(int argc, char **argv)
{
	int bound;
	unsigned long long largest_num; // starting num with largest chain

	(argc == 2) ? (bound = atoi(argv[1])) : (bound = DEFAULT);

	largest_num = search_for_chains(bound);

	printf("\nThe starting number with the largest Collatz sequence");
	printf(" below %d is %llu\n\n", bound, largest_num);

	return 0;
}
