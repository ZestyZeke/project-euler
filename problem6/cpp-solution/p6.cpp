/*
 * p6.cpp
 *
 * Problem 6:
 * Find the difference between the sum of the squares of the first n
 * natural numbers and the square of the sum of the first n natural
 * numbers.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define 	TEST	    10
#define         DEFAULT     100
using namespace std;

int difference(const int n)
{
	vector<int> nums (n);
	vector<int> sqrs (n);
	iota(nums.begin(), nums.end(), 1);
	transform(nums.begin(), nums.end(), sqrs.begin(),
			[](const int n) { return n * n; });
	int diff = accumulate(nums.begin(), nums.end(), 0);
	diff = diff * diff - accumulate(sqrs.begin(), sqrs.end(), 0);
	if (diff < 0) diff *= -1;
	return diff;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
        int n;
        (argc == 2) ? (n = stoi(argv[1])) : (n = DEFAULT);

	int answer = difference(n);

        cout << "\nThe difference between the sum of the squares";
        cout << " and the square of the sum of the first " << n;
        cout << " natural numbers is: " << answer << "\n\n";

        return 0;
}
