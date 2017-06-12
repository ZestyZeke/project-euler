/*
 * p17.c
 *
 * Zeke Reyna
 *
 * Number letter counts:
 * If all the numbers from 1 to 1000 inclusive were written out in words,
 * how many letters would be used?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define		LINES		31
#define		LETTERS_PER	20
#define		LOWER_BOUND	1
#define		UPPER_BOUND	5

/*
 * idea is to read in the contents of the file
 * into a char matrix, where each line would correspond to a (char *)
 * that way access would be faster
 */
void process(FILE *fp, char contents[LINES][LETTERS_PER])
{
	int i, line;
	size_t line_length;

	for (i = 0; i < LINES; i++)
		memset(contents[i], '\0', LETTERS_PER * sizeof(char));

	line = 0;
	while (fgets(contents[line++], LETTERS_PER, fp) != NULL)
		;

	// get rid of '\n'
	for (i = 0; i < LINES; i++) {
		line_length = strlen(contents[i]);
		contents[i][--line_length] = '\0';
	}
}

unsigned long long count(int pos, char file_contents[LINES][LETTERS_PER])
{
	unsigned long long retval = 0;
	retval += (unsigned long long) strlen(file_contents[pos]);
	//printf("%s ", file_contents[pos]);
	return retval;
}

unsigned long long find_letters_in_num(int num,
char file_contents[LINES][LETTERS_PER])
{
	unsigned long long sum = 0;

	if (0 <= num && num <= 20) {

		sum += count(num, file_contents);

	} else if (21 <= num && num <= 99) {

		// tens place
		int tens_place = num / 10;
		int ones_place = num % 10;

		sum += count(18 + tens_place, file_contents);
		// 18 seems arbitrary but spot 20 is where the tens place start
		// in the file
		if (ones_place != 0)
			sum += count(ones_place, file_contents);

	} else if (num == 100) {

		// one
		sum += count(1, file_contents);
		// hundred
		sum += count(28, file_contents);

	} else if (100 < num && num < 1000) {

		int hundreds_place = num / 100;
		int tens_place = num / 10 % 10;
		int ones_place = num % 10;

		// hundreds
		sum += count(hundreds_place, file_contents);

		// hundred
		sum += count(28, file_contents);

		// and
		sum += count(30, file_contents);

		// tens and ones place
		int tens_and_ones = num % 100;

		if (tens_and_ones == 0) {

			// need to get rid of 'and' letters then exit
			sum -= count(30, file_contents);

		} else if (0 < tens_and_ones && tens_and_ones <= 20) {

			sum += count(tens_and_ones, file_contents);

		} else if (21 <= tens_and_ones && tens_and_ones <= 99) {

			sum += count(18 + tens_place, file_contents);
			if (ones_place != 0)
				sum += count(ones_place, file_contents);

		}

	} else if (num == 1000) {

		// one
		sum += count(1, file_contents);
		// thousand
		sum += count(29, file_contents);

	} else {
		printf("upper bound is too large, currently not supported\n");
	}

	// delete when works
	//printf("\n");
	return sum;
}

int main(int argc, char **argv)
{
	FILE *fp;
	char file_contents[LINES][LETTERS_PER];
	int lower_bound, upper_bound;
	int num;
	unsigned long long sum_of_letters;

	if (argc == 3) {
		lower_bound = atoi(argv[1]);
		upper_bound = atoi(argv[2]);
	} else {
		lower_bound = LOWER_BOUND;
		upper_bound = UPPER_BOUND;
	}

	fp = fopen("./num_words_for_c.txt", "r");

	process(fp, file_contents);

	sum_of_letters = 0;
	for (num = lower_bound; num <= upper_bound; num++)
		sum_of_letters += find_letters_in_num(num, file_contents);

	printf("\nThe sum of the letters from %d to %d is: %llu\n\n",
			lower_bound, upper_bound, sum_of_letters);

	fclose(fp);
	return 0;
}
