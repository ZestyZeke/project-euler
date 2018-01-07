/*
 * p3-old.cpp
 *
 * Zeke Reyna
 *
 * Problem 3:
 * What is the largest prime factor of the number 600851475143 ?
 *
 * note: this solution depends on using the sqrt(n) as the upper bound which
 * is incorrect. this doesn't solve for all numbers exactly, so beware
 */

#include <iostream>
#include <vector>
#include <math.h>
#define     TEST    13195
#define     DEFAULT 600851475143
using namespace std;

typedef unsigned long long ull;

bool check_if_pf(const ull factor, const vector<ull>& pfs)
{
        for (auto it = pfs.begin(); it < pfs.end(); ++it) {
                if (factor % *it == 0)
                        return false;
        }
        return true;
}

ull find_largest_pf(const ull num)
{
        ull i;
        ull largest_pf = 1;
        vector<ull> pfs;

        for (i = 2; i < (ull) sqrtl(num); i++) {
                if (num % i == 0 && check_if_pf(i, pfs))
                        pfs.push_back(i);
        }

        if (!pfs.empty())
                largest_pf = pfs.back();
        if (largest_pf == 1)
                largest_pf = num;

        return largest_pf;
}

int main(int argc, char **argv)
{
        ull num;
        ull largest;
        (argc == 2) ? (num = atoi(argv[1])) : (num = DEFAULT);

        largest = find_largest_pf(num);

        cout<<"\nThe largest prime factor of the number "<<num<<" is: ";
        cout<<largest<<"\n\n";

        return 0;
}
