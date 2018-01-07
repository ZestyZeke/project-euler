/*
 * p9.c
 *
 * Zeke Reyna
 *
 * Problem 9:
 * There exists one pythagorean triplet such that a + b + c = 100.
 * Find the product a * b * c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define		LIMIT		1000
#define		SQR(x)		((x)*(x))

int find_c(int a, int b)
{
	int c = (int) sqrt(SQR(a) + SQR(b));
	if (SQR(c) != SQR(a) + SQR(b))
		c = -1;
	return c;
}

int main(int argc, char **argv)
{
	int sum_limit;
	int i, j, c;
	int product;

	(argc == 2) ? (sum_limit = atoi(argv[1])) : (sum_limit = LIMIT);

	product = -1;
	for (i = 1; i < sum_limit; i++) {
		for (j = 1; j < sum_limit; j++) {
			c = find_c(i, j);
			if (c != -1 && i + j + c == sum_limit)
				goto found;
		}
	}
found:
	product = i * j * c;
	printf("\nThe product of the pythagorean triplets that sum to ");
	printf("%d is %d\n\n", sum_limit, product);
	return 0;
}
