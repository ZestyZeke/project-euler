/*
 * p8.cpp
 *
 * Zeke Reyna
 *
 * Problem 8:
 * Find the thirteen digits in the 100-digit number <../100-digit-number.txt>
 * that have the greatest product. What is the value of this product?
 */

#include <iostream>
#include <fstream>
#include <sstream>

#define		BUF_SIZE	2048
#define		ADJACENT	13

using namespace std;

long long find_product(char *buf_pos, int adj)
{
	long long product = 1;
	for (int i = 0; i < adj; i++)
		product *= buf_pos[i] - '0'; //convert char to int
	return product;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	char buffer[BUF_SIZE];
	int i;
	int adj;
	long long largest_product, curr_product;

	(argc == 2) ? (adj = stoi(argv[1])) : (adj = ADJACENT);

	ifstream file ("../100-digit-number.txt", ios::in);
	file.read(buffer, BUF_SIZE);

	largest_product = -1;
	for (i = 0; buffer[i + adj] != '\0'; i++) {
		curr_product = find_product(&buffer[i], adj);
		if (curr_product > largest_product)
			largest_product = curr_product;
	}

	cout << "\nThe largest product of the " << adj << " adjacent digits in";
	cout << " 100-digit-number.txt is " << largest_product << "\n\n";
	return 0;
}
