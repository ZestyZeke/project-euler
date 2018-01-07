/*
 * p9.cpp
 *
 * Zeke Reyna
 *
 * Problem 9:
 * There exists one pythagorean triplet such that a + b + c = sum.
 * Find the product a * b * c.
 */

#include <iostream>
#include <cmath>

#define		SUM_LIMIT		1000
#define		SQR(x)			((x)*(x))

using namespace std;

int find_c(int a, int b)
{
	int c = (int) sqrt(SQR(a) + SQR(b));
	if (SQR(c) != SQR(a) + SQR(b))
		c = -1;
	return c;
}

int main(int argc, char **argv)
{
	int sum;
	int a, b, c;
	int product;

	(argc == 2) ? (sum = stoi(argv[1])) : (sum = SUM_LIMIT);

	product = -1;
	for (a = 1; a < sum; a++) {
		for (b = 1; b < sum; b++) {
			c = find_c(a, b);
			if (c != -1 && a + b + c == sum)
				goto found;
		}
	}
found:
	product = a * b * c;
	cout << "\nThe product of the pythagorean triplets that sum to ";
	cout << sum << " is " << product << "\n\n";
	return 0;
}
