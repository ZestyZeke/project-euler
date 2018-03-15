/*
 * p5.cpp
 *
 * Zeke Reyna
 *
 * Problem 5:
 * What is the smallest positive number that is evenly divisible by all of
 * the numbers from 1 to 20?
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ull = unsigned long long;
const ull _TEST = 10;
const ull _DEFAULT = 20;

vector<int> generate_divisors(const int bound)
{
        vector<int> divis;
        for (int num = 1; num <= bound; num++) {
                bool redundant = false;
                for (int i = num + 1; i <= bound; i++) {
                        if (i % num == 0) {
                                redundant = true;
                                break;
                        }
                }
                if (!redundant)
                        divis.push_back(num);
        }
        return divis;
}

ull find_first_divisible_num(const vector<int> divisors, const int bound)
{
        ull num = (ull) bound;
        bool found = false;

        while (!found && num++) {
		found = all_of(divisors.begin(), divisors.end(),
				[num](const int d) { return num % d == 0; });
        }
        return num;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
        int bound;
        (argc == 2) ? (bound = atoi(argv[1])) : (bound = _DEFAULT);

        vector<int> divisors = generate_divisors(bound);

        ull num = find_first_divisible_num(divisors, bound);

        cout<<"\nThe smallest positive number that is divisible by all of";
        cout<<" the numbers from 1 to "<<bound<<" is: "<<num<<"\n\n";

        return 0;
}
