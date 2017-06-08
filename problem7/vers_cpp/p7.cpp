/*
 * p7.cpp
 *
 * Zeke Reyna
 *
 * A simple file used to find the nth prime number.
 */

#include <iostream>
#include <list>
#include <cmath>

#define BOUND 7

using namespace std;

int generate_upper(int n);
void generate_nums(list<int>& nums, int bound);
int sieve(list<int>& nums, int n);

int generate_upper(int n)
{
        double term1, term2;
        term1 = n * log(n);
        term2 = n * log(log(n));
        return (int) (term1 + term2);
}

void generate_nums(list<int>& nums, int bound)
{
        int i;
        for (i = 2; i < bound; i++) {
                nums.push_back(i);
        }
}

int sieve(list<int>& nums, int n)
{
        int temp_n, temp_prime;

        temp_n = 1;
        for (auto i1 = nums.begin(); i1 != nums.end() && temp_n <= n; ++i1) {

                temp_prime = *i1;
                for (auto i2 = next(i1); i2 != nums.end(); ) {

                        if (*i2 % temp_prime == 0) {
                                auto i_temp = i2;
                                ++i2;
                                nums.erase(i_temp);
                        } else {
                                ++i2;
                        }
                }
                temp_n++;
        }
        return temp_prime;
}

// use forward_list
// to compare time against java and python later.
int main(int argc, char **argv)
{
        int n;
        int upperbound;
        int nth_prime;
        //forward_list<int> nums;
        list<int> nums;

        (argc == 2) ? (n = stoi(argv[1])) : (n = BOUND);

        upperbound = generate_upper(n);

        generate_nums(nums, upperbound);

        nth_prime = sieve(nums, n);

        cout << "\nThe " << n << "th prime number is " <<  nth_prime << "\n\n";

        return 0;
}
