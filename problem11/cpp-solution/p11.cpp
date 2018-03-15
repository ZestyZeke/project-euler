/*
 * p11.cpp
 *
 * Zeke Reyna
 *
 * Problem 11:
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20x20 grid <20x20-grid.txt>?
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define		SIZE		20
#define		BUF_SIZE	2048
#define		MAX_SIZE	50

using namespace std;

/*
 * x000
 * 0x00
 * 00x0
 * 000x
 */
int diag1(int mat[][SIZE], int size)
{
	int row, col;
	int prod, retval;

	retval = 0;
	for (row = 0; row <= size - 4; row++) {
		for (col = 0; col <= size - 4; col++) {
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
int diag2(int mat[][SIZE], int size)
{
	int row, col;
	int prod, retval;

	retval = 0;
	for (row = 0; row <= size - 4; row++) {
		for (col = 0; col <= size - 4; col++) {
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
int horiz(int mat[][SIZE], int size)
{
	int row, col;
	int prod, retval;

	retval = 0;
	for (row = 0; row <= size - 1; row++) {
		for (col = 0; col <= size - 4; col++) {
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
int vert(int mat[][SIZE], int size)
{
	int row, col;
	int prod, retval;

	retval = 0;
	for (row = 0; row <= size - 1; row++) {
		for (col = 0; col <= size - 4; col++) {
			prod  = mat[row][col] * mat[row][col + 1];
			prod *= mat[row][col + 2] * mat[row][col + 3];
			if (prod > retval)
				retval = prod;
		}
	}
	return retval;
}

void process_file(int mat[][SIZE], int size)
{
	ifstream infile("../20x20-grid.txt");
	if (infile.is_open()) {
		string line;
		for (int i = 0; getline(infile, line); i++) {
			istringstream iss(line);
			for (int j = 0; j < size; j++) {
				string num;
				iss >> num;
				mat[i][j] = stoi(num);
			}
		}
		infile.close();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int size = SIZE;
	int mat[SIZE][SIZE];

	process_file(mat, size);

	int largest_adj = diag1(mat, size);

	int temp = diag2(mat, size);
	if (temp > largest_adj) largest_adj = temp;

	temp = horiz(mat, size);
	if (temp > largest_adj) largest_adj = temp;

	temp = vert(mat, size);
	if (temp > largest_adj) largest_adj = temp;

	cout << "\nThe largest product of 4 adjacent numbers in a line in ";
	cout << "20x20-grid.txt is " << largest_adj << "\n\n";
	return 0;
}
