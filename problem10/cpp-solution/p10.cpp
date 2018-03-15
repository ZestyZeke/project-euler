/*
 * p10.cpp
 *
 * Zeke Reyna
 *
 * Problem 10:
 * Find the sum of all the primes below two million.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ull = unsigned long long;
const int _BOUND_DEF = 2000000;

vector<int> generate_primes(int bound)
{
	vector<int> primes;
	for (int num = 2; num < bound; num++) {
		bool isPrime = none_of(primes.begin(), primes.end(),
				[num](const int p) { return num % p == 0; });
		if (isPrime)
			primes.push_back(num);
	}
	return primes;
}

ull sum_primes(vector<int>& primes)
{
	return accumulate(primes.begin(), primes.end(), 0);
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	(argc == 2) ? (n = stoi(argv[1])) : (n = _BOUND_DEF);

	vector<int> primes = generate_primes(n);
	ull sum = sum_primes(primes);

	cout << "\nThe sum of the primes below " << n;
	cout << " is " << sum << "\n\n";
	return 0;
}
