/*
 * p3.cpp
 *
 * Zeke Reyna
 *
 * Problem 3:
 * What is the largest prime factor of the number 600851475143 ?
 *
 * note: Solves for all numbers that are within the bounds of
 * 'unsigned long long'
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
using ull = unsigned long long;
const ull _TEST = 13195;
const ull _DEFAULT = 600851475143;
const ull _NOT_PF = 1;

vector<ull> make_list_of_facts(const ull num)
{
        vector<ull> facts;
        for (ull i = 2; i < (ull) sqrtl(num) + 1; i++) {
                if (num % i == 0) {
                        facts.push_back(i);
                        facts.push_back(num / i);
                }
        }
        return facts;
}

bool is_prime(const ull num)
{
        bool retval = true;
        for (ull i = 2; i <= (ull) sqrtl(num) + 1; i++) {
                if (num % i == 0) {
                        retval = false;
                        break;
                }
        }
        return retval;
}

ull find_largest_pf(const ull num)
{
        vector<ull> pfs = make_list_of_facts(num);

	for_each(pfs.begin(), pfs.end(),
			[](ull& f){ if (!is_prime(f)) f = _NOT_PF; });

	ull largest = *max_element(pfs.begin(), pfs.end());
        if (largest == 1)
                largest = num;
        return largest;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
        ull num;
        (argc == 2) ? (num = atoi(argv[1])) : (num = _DEFAULT);

        ull largest = find_largest_pf(num);

        cout<<"\nThe largest prime factor of the number "<<num<<" is: ";
        cout<<largest<<"\n\n";

        return 0;
}
