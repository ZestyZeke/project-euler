/*
 * p8.c
 *
 * Zeke Reyna
 *
 * Problem 8:
 * Find the thirteen digits in the 100-digit number <../100-digit-number.txt>
 * that have the greatest product. What is the value of this product?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		BUF_SIZE	4096
#define		ADJACENT	13

long long find_product(char *buf_pos, int adj)
{
	long long product = 1;
	for (int i = 0; i < adj; i++)
		product *= buf_pos[i] - '0'; // convert char to int
	return product;
}

int main(int argc, char **argv)
{
	char buffer[BUF_SIZE];
	FILE *fp;
	int i;
	int adj;
	long long largest_product;
	long long curr_product;

	(argc == 2) ? (adj = atoi(argv[1])) : (adj = ADJACENT);

	fp = fopen("../100-digit-number.txt", "r");
	fgets(buffer, BUF_SIZE, fp);
	fclose(fp);

	largest_product = -1;
	for (i = 0; buffer[i + adj] != '\0'; i++) {
		curr_product = find_product(&buffer[i], adj);
		if (curr_product > largest_product)
			largest_product = curr_product;
	}

	printf("\nThe largest product of the %d adjacent digits", adj);
	printf(" in 100-digit-number.txt is %lld\n\n", largest_product);
	return 0;
}
