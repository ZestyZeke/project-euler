/*
 * p4.cpp
 *
 * Zeke Reyna
 *
 * A simple C file to find the largest palindrome
 * That's a product of two 3 digit numbers.
 */

#include <iostream>
#include <string>
#include <algorithm>

#define SIZE 100
#define LOWERBOUND 100
#define UPPERBOUND 1000

using namespace std;

int check_if_pal(int i, int j)
{
	string num = to_string(i * j);
	string front;
	string end;
    int half_length;
    int retval;

    half_length = num.length() / 2;

	if (num.length() % 2 == 0) {
            front = num.substr(0, half_length);
            end   = num.substr(half_length, half_length);
    } else {
            front = num.substr(0, half_length);
            end   = num.substr(half_length + 1, half_length);
    }

    reverse(end.begin(), end.end());

    (front == end) ? (retval = i * j) : (retval = -1);

    return retval;
}

int main(int argc, char **argv)
{
	int i, j;
	int cur_pal;
	int largest_pal = 0;
	int lowerbound, upperbound;

	if (argc == 3) {
		upperbound = atoi(argv[2]);
		lowerbound = atoi(argv[1]);
	} else {
		upperbound = UPPERBOUND;
		lowerbound = LOWERBOUND;
	}

	for (i = lowerbound; i < upperbound; i++) {
		for (j = i; j < upperbound; j++) {

			cur_pal = check_if_pal(i, j);
			if (cur_pal > largest_pal)
				largest_pal = cur_pal;
		}
	}

	cout << "\nThe largest palindrome ";
	cout << "that is a sum of two products between ";
	cout << "the bounds " << lowerbound <<" and " << upperbound << " is: ";
	cout << largest_pal << "\n\n";

	return 0;
}
