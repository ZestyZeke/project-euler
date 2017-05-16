/*
 * p13.cpp
 *
 * Zeke Reyna
 *
 * Sums 100 50-digit numbers.
 */

#include <iostream>
#include <fstream>
#include <vector>
#define BUF_SIZE 2048
using namespace std;

void process(int nums[100][50])
{
        int i, j;
        string line;
        ifstream fs;

        fs.open("../num-alt.txt", ios::in);

        i = 0;
        while (getline(fs, line) && i < 100) {
                for (j = 0; j < 50; j++) {
                        nums[i][j] = line[j] - '0';
                }
                i++;
        }
        fs.close();
}

void sum_nums(int nums[100][50], vector<int>& sum)
{
        int i, j;
        unsigned long long temp, carry;

        carry = 0;
        for (j = 50; j >= 0; j--) {
                temp = 0;
                for (i = 0; i < 100; i++)
                        temp += nums[i][j];

                temp += carry;
                sum.push_back((int)(temp % 10));
                carry = temp / 10;
        }

        while (carry > 0) {
                sum.push_back((int)(carry % 10));
                carry /= 10;
        }
}

void print_sum(vector<int>& sum)
{
        int j;

        for (auto i = sum.rbegin(); i != sum.rend(); ++i)
                cout<<*i;

        cout<<"\nThe first ten digits are:\n";
        j = 0;
        for (auto i = sum.rbegin(); i != sum.rend() && j < 10; ++i, ++j)
                cout<<*i;

}

int main(int argc, char **argv)
{
        int nums[100][50];
        vector<int> sum;

        process(nums);

        sum_nums(nums, sum);

        cout<<"\nThe sum of all those numbers is:\n";
        print_sum(sum);
        printf("\n\n");

        return 0;
}
