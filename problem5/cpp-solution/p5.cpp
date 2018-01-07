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
#define             TEST        10
#define             DEFAULT     20
using namespace std;

vector<int> generate_divisors(const int bound)
{
        vector<int> divis;

        int num, i;
        bool redundant;
        for (num = 1; num <= bound; num++) {
                redundant = false;
                for (i = num + 1; i <= bound; i++) {
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

long long find_first_divisible_num(const vector<int> divisors, const int bound)
{
        long long num = (long long) bound;
        bool found = false;

        while (!found && num++) {
                found = true;
                for (auto it = divisors.begin(); it != divisors.end(); ++it) {
                        if (num % *it != 0) {
                                found = false;
                                break;
                        }
                }
        }

        return num;
}

int main(int argc, char **argv)
{
        int bound;
        (argc == 2) ? (bound = atoi(argv[1])) : (bound = DEFAULT);

        vector<int> divisors = generate_divisors(bound);

        long long num = find_first_divisible_num(divisors, bound);

        cout<<"\nThe smallest positive number that is divisible by all of";
        cout<<" the numbers from 1 to "<<bound<<" is: "<<num<<"\n\n";

        return 0;
}
