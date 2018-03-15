/*
 * p2.cpp
 *
 * Zeke Reyna
 *
 * Problem 2:
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 *
 * note: solves for positive bounds other than four million that do not exceed
 * the bounds of 'int'
 */
#include <iostream>
using namespace std;
using ull = unsigned long long;
const ull _DEFAULT = 4000000;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
        ull bound;
        (argc == 2) ? (bound = atoi(argv[1])) : (bound = _DEFAULT);

        // first two fib nums
        ull first  = 1;
        ull second = 1;
        ull sum    = 0;

	while (second < bound) {
                if (second % 2 == 0)
			sum += second;
		ull temp = first + second;
		first = second;
		second = temp;
        }

        cout<<"\nThe sum of the even-valued Fibonacci numbers under the bound ";
        cout<<bound<<" is: "<<sum<<"\n\n";
	return 0;
}
