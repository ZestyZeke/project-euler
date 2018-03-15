/*
 * p12.cpp
 *
 * Zeke Reyna
 *
 * Problem 12:
 * What is the value of the first triangle number to have over five hundred
 * divisors?
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int _DEFAULT = 500;

int triangle(const int n)
{
	return (n * n + n) / 2;
}

int count_divisors(int num)
{
	int num_factors = 1;
	for (int i = 2; i < (int) sqrt(num); i++) {
		int power = 0;
		while (num % i == 0) {
			num /= i;
			power++;
		}
		num_factors *= (power + 1);
	}
	if (num > 1) num_factors *= 2;
	return num_factors;
}

int alternate_count(int num)
{
	vector<int> nums ((int) sqrt(num) - 1);
	iota(nums.begin(), nums.end(), 1);
	return 2 * count_if(nums.begin(), nums.end(),
			[num](const int d) { return num % d == 0; });
}

int find(const int num_divisors)
{
	bool found = false;
	int num = 1;
	for (int i = 1; !found; i++) {
		num = triangle(i);
		if (count_divisors(num) > num_divisors) found = true;
		//if (alternate_count(num) > num_divisors) found = true;
	}
	return num;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	(argc == 2) ? (n = stoi(argv[1])) : (n = _DEFAULT);

	cout << "\nThe first triangular number that has greater than " << n;
	cout << " divisor is: " << find(n) << "\n\n";
	return 0;
}
