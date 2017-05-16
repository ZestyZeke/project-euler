/*
 * p13.c
 *
 * Zeke Reyna
 *
 * find the first 10 digits of the sum of the 100 50-digit
 * numbers, given in num.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4096

/*
 * note: file is 100 50 digit numbers
 * which amounts to 5000 characters
 * two read's should work to get all
 */
void process(int nums1[BUF_SIZE], int nums2[BUF_SIZE])
{
	char buffer[BUF_SIZE];
	FILE *fp;
	int i;

	// use -1 as null pointer for int array
	memset(nums1, -1, BUF_SIZE);
	memset(nums2, -1, BUF_SIZE);
	memset(buffer, 0, BUF_SIZE);
	fp = fopen("num.txt", "r");

	fgets(buffer, BUF_SIZE, fp);
	for (i = 0; i < BUF_SIZE; i++ ) {
		nums1[i] = buffer[i] - '0';
	}

	memset(buffer, 0, BUF_SIZE);
	fgets(buffer, BUF_SIZE, fp);
	for (i = 0; buffer[i] != 0; i++ ) {
		nums2[i] = buffer[i] - '0';
	}

}

unsigned long long power(int num, int exp)
{
	int i;
	unsigned long long retval;

	retval = num;
	for (i = 1; i < exp; i++)
		retval *= num;

	return retval;
}

unsigned long long sum_nums(int nums1[BUF_SIZE], int nums2[BUF_SIZE])
{
	int i;
	unsigned long long large_sum;

	large_sum = 0;
	for (i = 0; i < BUF_SIZE; i += 50) {
		large_sum += nums1[i] * power(10, 7);
		large_sum += nums1[i + 1] * power(10, 6);
		large_sum += nums1[i + 2] * power(10, 5);
		large_sum += nums1[i + 3] * power(10, 4);
		large_sum += nums1[i + 4] * power(10, 3);
		large_sum += nums1[i + 5] * power(10, 2);
		large_sum += nums1[i + 6] * 10;
		large_sum += nums1[i + 7];
	}

	i--; // because i - BUF_SIZE gives the ith position not position i
	for (i %= BUF_SIZE; nums2[i] != -1; i += 50) {
		large_sum += nums2[i] * power(10, 7);
		large_sum += nums2[i + 1] * power(10, 6);
		large_sum += nums2[i + 2] * power(10, 5);
		large_sum += nums2[i + 3] * power(10, 4);
		large_sum += nums2[i + 4] * power(10, 3);
		large_sum += nums2[i + 5] * power(10, 2);
		large_sum += nums2[i + 6] * 10;
		large_sum += nums2[i + 7];
	}

	return large_sum;
}

int main( int argc, char **argv )
{
	int nums1[BUF_SIZE];
	int nums2[BUF_SIZE];
	unsigned long long large_sum;

	process(nums1, nums2);
	/*
	 * at this point, nums1 should be filled, and nums2 should be partially
	 * filled, with '-1' as a null terminator
	 */

	large_sum = sum_nums(nums1, nums2);

	printf("\nThe first digits of the large sum is %llu\n\n", large_sum);

	return 0;
}
