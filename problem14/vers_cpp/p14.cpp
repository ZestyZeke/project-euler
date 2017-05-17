/*
 * p14.cpp
 *
 * Zeke Reyna
 *
 * Finds the largest Collatz sequence under a given bound.
 */

#include <iostream>
#include <vector>
#define DEFAULT 10
using namespace std;
typedef unsigned long long ull;

vector<ull> search_for_chains(int bound)
{
        ull i;
        ull largest_num, largest_seq;
        ull temp_num, temp_seq;
        vector<ull> nums;

        largest_num = 0;
        largest_seq = 0;
        for (i = 2; i < (ull) bound; i++) {

                temp_seq = 0;
                for (temp_num = i; temp_num != 1; temp_seq++) {

                        if (temp_num % 2 == 0)
                                temp_num /= 2;
                        else
                                temp_num = 3 * temp_num + 1;
                }

                if (temp_seq > largest_seq) {
                        largest_seq = temp_seq;
                        largest_num = i;
                }
        }
        nums.push_back(largest_seq);
        nums.push_back(largest_num);
        return nums;
}

int main(int argc, char **argv)
{
        int bound;
        vector<ull> largest;
        ull num, seq;

        (argc == 2) ? (bound = stoi(argv[1])) : (bound = DEFAULT);

        largest = search_for_chains(bound);
        num = largest.back();
        seq = largest.front();

        cout<<"\nThe starting number with the largest Collatz sequence below";
        cout<<" "<<bound<<" is "<<num<<" and the length of its";
        cout<<" sequence is "<<seq<<"\n\n";
}
