/*
 * p3.cpp
 *
 * Zeke Reyna
 *
 * Problem 3:
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <vector>
#include <math.h>
#define     TEST    13195
#define     DEFAULT 600851475143
#define     NOT_PF  1
using namespace std;

typedef unsigned long long ull;

vector<ull> make_list_of_facts(const ull num)
{
        vector<ull> facts;
        ull i;
        for (i = 2; i < (ull) sqrtl(num) + 1; i++) {
                if (num % i == 0) {
                        facts.push_back(i);
                        facts.push_back(num / i);
                }
        }
        return facts;
}

bool is_prime(const ull num)
{
        ull i;
        bool retval = true;
        for (i = 2; i <= (ull) sqrtl(num) + 1; i++) {
                if (num % i == 0) {
                        retval = false;
                        break;
                }
        }
        return retval;
}

void prune_facts(vector<ull>& facts)
{
        auto iter = facts.begin();
        for (; iter != facts.end(); ++iter) {
                if (!is_prime(*iter))
                        *iter = NOT_PF;
        }
}

ull find_max(const vector<ull>& pfs)
{
        ull max = 0;
        auto iter = pfs.begin();
        for (; iter != pfs.end(); ++iter) {
                if (*iter > max)
                        max = *iter;
        }
        return max;
}

ull find_largest_pf(const ull num)
{
        vector<ull> pfs;
        pfs = make_list_of_facts(num);

        prune_facts(pfs);

        ull largest = find_max(pfs);
        if (largest == 1)
                largest = num;
        return largest;
}

int main(int argc, char **argv)
{
        ull num, largest;
        (argc == 2) ? (num = atoi(argv[1])) : (num = DEFAULT);

        largest = find_largest_pf(num);

        cout<<"\nThe largest prime factor of the number "<<num<<" is: ";
        cout<<largest<<"\n\n";

        return 0;
}
