/*
 * p13-alt.c
 *
 * Zeke Reyna
 *
 * Sums 100 50-digit numbers. This time, using string manipulation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 2048
#define EST_SIZE 200

void process(int nums[100][50])
{
	int i, j;
	FILE *fp;
	char buffer[BUF_SIZE];

	fp = fopen("../num-alt.txt", "r");

	memset(buffer, 0, BUF_SIZE);
	for (i = 0; fgets(buffer, BUF_SIZE, fp) != NULL; i++) {
		for (j = 0; buffer[j] != '\0' && buffer[j] != '\n'; j++) {
			nums[i][j] = buffer[j] - '0';
		}
	}
	fclose(fp);
}

void sum_nums(int nums[100][50], int sum[EST_SIZE])
{
	int row, col;
	unsigned long long temp_sum;
	unsigned long long carry;
	int i;

	carry = 0;
	i = EST_SIZE;
	for (col = 49; col >= 0; col--) {

		temp_sum = 0;
		for (row = 0; row < 100; row++) {
			temp_sum += nums[row][col];
		}

		temp_sum += carry;
		sum[--i] = (int) (temp_sum % 10);
		carry = temp_sum / 10;
	}

	// need to move leftover carryinto sum
	while (carry > 0) {
		sum[--i] = (int) (carry % 10);
		carry /= 10;
	}
}

void print_sum(int sum[EST_SIZE])
{
	int i, j;
	int front;

	// not sure why there are 0's
	for (i = 0; sum[i] == -1 || sum[i] == 0; i++)
		;

	front = i;
	for (; i < EST_SIZE; i++)
		printf("%d", sum[i]);

	printf("\nThe first ten digits are:\n");
	for (j = 0; j < 10; j++)
		printf("%d", sum[front++]);
}

int main(int argc, char **argv)
{
	int nums[100][50];
	int sum[EST_SIZE];

	process(nums);

	memset(sum, -1, EST_SIZE);
	sum_nums(nums, sum);

	printf("\nThe sum of all those numbers is:\n");
	print_sum(sum);
	printf("\n\n");

	return 0;
}
