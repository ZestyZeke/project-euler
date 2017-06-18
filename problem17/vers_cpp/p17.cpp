/*
 * p17.cpp
 *
 * Zeke Reyna
 *
 * Number Letter Counts:
 * If all the numbers from 1 to 1000 inclusive were written out in words,
 * how many letters would be used?
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define     LOWER_BOUND     1
#define     UPPER_BOUND     5
#define     LINES           5
#define     WORDS_PER       10
using namespace std;

typedef unsigned long long ull;

void print_file_contents(const string file_contents[LINES][WORDS_PER])
{
        int word, line;
        for (line = 0; line < LINES; line++) {
                for (word = 0; word < WORDS_PER; word++)
                        cout << file_contents[line][word] << " ";
                cout << "\n";
        }
}

void process(const string file_name, string file_contents[LINES][WORDS_PER])
{
        ifstream nums_file;
        string nums_line;
        int word, line;

        nums_file.open(file_name, ios::in);

        for (line = 0; line < LINES && getline(nums_file, nums_line); line++) {

                istringstream this_line(nums_line);
                for (word = 0; word < WORDS_PER && !this_line.eof(); word++) {

                        this_line >> file_contents[line][word];
                }
        }

        //print_file_contents(file_contents);
        nums_file.close();
}

ull count(int line, int word, const string file_contents[LINES][WORDS_PER])
{
        ull retval = 0;
        retval = (ull) file_contents[line][word].size();
        //cout << file_contents[line][word] << " ";
        return retval;
}

ull find_num_letters(const int num, const string file_contents[LINES][WORDS_PER])
{
        ull num_letters = 0;

        const int thousands_place= num / 1000;
        const int hundreds_place = num / 100 % 10;
        const int tens_place     = num / 10 % 10;
        const int ones_place     = num % 10;

        // thousands
        if (0 < thousands_place) {
                num_letters += count(0, thousands_place, file_contents);

                // thousand
                num_letters += count(3, 1, file_contents);
        }

        // hundreds
        if (0 < hundreds_place && hundreds_place < 10) {
                num_letters += count(0, hundreds_place, file_contents);

                // hundred
                num_letters += count(3, 0, file_contents);

                // and
                if ((tens_place + ones_place) > 0)
                        num_letters += count(4, 0, file_contents);
        }

        // teens
        if (tens_place == 1)
                num_letters += count(1, ones_place, file_contents);

        // tens
        if (tens_place > 1)
                num_letters += count(2, tens_place - 2, file_contents);

        // ones
        if (0 < ones_place && tens_place != 1)
                num_letters += count(0, ones_place, file_contents);

        //cout<<"\n";
        return num_letters;
}

int main(int argc, char **argv)
{
        int num;
        int lower_bound, upper_bound;

        if (argc == 3) {
                lower_bound = stoi(argv[1]);
                upper_bound = stoi(argv[2]);
        } else {
                lower_bound = LOWER_BOUND;
                upper_bound = UPPER_BOUND;
        }

        const string file_name = "../num_words.txt";
        string file_contents[LINES][WORDS_PER];

        process(file_name, file_contents);

        ull sum_of_letters = 0;
        for (num = lower_bound; num <= upper_bound; num++)
                sum_of_letters += find_num_letters(num, file_contents);

        cout << "\nThe sum of the letters from " << lower_bound << " to ";
        cout << upper_bound << " is: " << sum_of_letters << "\n\n";

        return 0;
}
