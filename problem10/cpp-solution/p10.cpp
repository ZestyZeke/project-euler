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
#include <cmath>

#define		BOUND_DEF	2000000

using namespace std;

vector<int> generate_primes(int bound)
{
	vector<int> primes;
	for (int num = 2; num < bound; num++) {
		bool isPrime = true;
		for (auto iter = primes.begin();
		     iter != primes.end() && isPrime; ++iter) {
			if (num % *iter == 0)
				isPrime = false;
		}
		if (isPrime)
			primes.push_back(num);
	}
	return primes;
}

unsigned long long sum_primes(vector<int>& primes)
{
	unsigned long long sum = 0;
	for (auto iter = primes.begin(); iter != primes.end(); ++iter)
		sum += *iter;
	return sum;
}

int main(int argc, char **argv)
{
	int n;
	unsigned long long sum;
	vector<int> primes;

	(argc == 2) ? (n = stoi(argv[1])) : (n = BOUND_DEF);

	primes = generate_primes(n);
	sum = sum_primes(primes);

	cout << "\nThe sum of the primes below " << n;
	cout << " is " << sum << "\n\n";
	return 0;
}
