/*
 * p11.c
 *
 * Zeke Reyna
 *
 * Problem 11:
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20x20 grid <20x20-grid.txt>?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		SIZE		20
#define		BUF_SIZE	4096

/*
 * x000
 * 0x00
 * 00x0
 * 000x
 */
int diag1(int mat[SIZE][SIZE])
{
	int row, col;
	int prod, retval;

	retval = 0;
	for (row = 0; row <= SIZE - 4; row++) {
		for (col = 0; col <= SIZE - 4; col++) {
			prod  = mat[row][col] * mat[row + 1][col + 1];
			prod *= mat[row + 2][col + 2] * mat[row + 3][col + 3];
			if (prod > retval)
				retval = prod;
		}
	}
	return retval;
}

/*
 * 000x
 * 00x0
 * 0x00
 * x000
 */
int diag2(int mat[SIZE][SIZE])
{
	int row, col;
	int prod, retval;

	retval = 0;
	for (row = 0; row <= SIZE - 4; row++) {
		for (col = 0; col <= SIZE - 4; col++) {
			prod  = mat[row][col + 3] * mat[row + 1][col + 2];
			prod *= mat[row + 2][col + 1] * mat[row + 3][col];
			if (prod > retval)
				retval = prod;
		}
	}
	return retval;
}

/*
 * xxxx
 */
int horiz(int mat[SIZE][SIZE])
{
	int row, col;
	int prod, retval;

	retval = 0;
	for (row = 0; row <= SIZE - 1; row++) {
		for (col = 0; col <= SIZE - 4; col++) {
			prod  = mat[row][col] * mat[row][col + 1];
			prod *= mat[row][col + 2] * mat[row][col + 3];
			if (prod > retval)
				retval = prod;
		}
	}
	return retval;
}

/*
 * x
 * x
 * x
 * x
 */
int vert(int mat[SIZE][SIZE])
{
	int row, col;
	int prod, retval;

	retval = 0;
	for (row = 0; row <= SIZE - 4; row++) {
		for (col = 0; col <= SIZE - 1; col++) {
			prod  = mat[row][col] * mat[row + 1][col];
			prod *= mat[row + 2][col] * mat[row + 3][col];
			if (prod > retval)
				retval = prod;
		}
	}
	return retval;
}

int main()
{
	int row, col;
	int mat[SIZE][SIZE];
	FILE *fp;
	int largest_adj;
	char buffer[BUF_SIZE];
	char *temp;
	int num;

	fp = fopen("../20x20-grid.txt", "r");
	row = 0;
	while (fgets(buffer, BUF_SIZE, fp) != NULL) {
		temp = strtok(buffer, " ");
		for (col = 0; col < SIZE; col++) {
			mat[row][col] = atoi(temp);
			temp = strtok(NULL, " \r\n");
		}
		row++;
	}
	fclose(fp);

	largest_adj = diag1(mat);

	num = diag2(mat);
	if (num > largest_adj) largest_adj = num;

	num = horiz(mat);
	if (num > largest_adj) largest_adj = num;

	num = vert(mat);
	if (num > largest_adj) largest_adj = num;

	printf("\nThe largest product of 4 adjacent numbers in a line in ");
	printf("20x20-grid.txt is %d\n\n", largest_adj);
	return 0;
}
