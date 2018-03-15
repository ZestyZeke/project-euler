/*
 * p7.cpp
 *
 * Zeke Reyna
 *
 * Problem 7:
 * What is the 10001st prime number?
 */

#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int _BOUND = 10001;

int generate_upper(int n)
{
	double term1, term2;
	term1 = n * log(n);
	term2 = n * log(log(n));
	return (int) (term1 + term2);
}

list<int> generate_nums(int bound)
{
	list<int> nums (bound - 2);
	iota(nums.begin(), nums.end(), 2);
	return nums;
}

int sieve(list<int>& nums, int n)
{
	int temp_prime = 1;
	int temp_n = 1;
	for (auto i1 = nums.begin(); i1 != nums.end() && temp_n <= n; ++i1) {
		temp_prime = *i1;
		for (auto i2 = next(i1); i2 != nums.end(); ) {
			if (*i2 % temp_prime == 0)
				i2 = nums.erase(i2);
			else
				++i2;
		}
		temp_n++;
	}
	return temp_prime;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	(argc == 2) ? (n = stoi(argv[1])) : (n = _BOUND);

	int upperbound = generate_upper(n);
	list<int> nums = generate_nums(upperbound);
	int nth_prime  = sieve(nums, n);

	cout << "\nThe " << n << "th prime number is " << nth_prime << "\n\n";

	return 0;
}
