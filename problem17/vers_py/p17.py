### p17.py
#
# Zeke Reyna
#
# Number Letter Counts:
# If all the numbers from 1 to 1000 inclusive were written out in words,
# how many letters would be used?

import sys

def process(file_name):

    f = open(file_name, "r")

    file_contents = []
    for line in f:
        file_contents.append(line.split())

    f.close()
    return file_contents

def find_num_letters(num, file_contents):

    num_letters = 0

    thousands_place = num // 1000 % 10
    hundreds_place  = num // 100  % 10
    tens_place      = num // 10   % 10
    ones_place      = num         % 10

    # thousands
    if thousands_place > 0:
        num_letters += len(file_contents[0][thousands_place])

        # thousand
        num_letters += len(file_contents[3][1])

    # hundreds
    if hundreds_place > 0:
        num_letters += len(file_contents[0][hundreds_place])

        # hundred
        num_letters += len(file_contents[3][0])

        # and
        if tens_place + ones_place > 0:
            num_letters += len(file_contents[4][0])

    # teens
    if tens_place == 1:
        num_letters += len(file_contents[1][ones_place])

    # tens
    if tens_place > 1:
        num_letters += len(file_contents[2][tens_place - 2])

    # ones
    if ones_place > 0 and tens_place != 1:
        num_letters += len(file_contents[0][ones_place])

    return num_letters

def main(argv):

    if len(argv) == 3:
        lower_bound = int(argv[1])
        upper_bound = int(argv[2])
    else:
        lower_bound = 1 # defaults
        upper_bound = 5

    file_contents = process("../num_words.txt")

    sum_of_letters = 0
    for num in range(lower_bound, upper_bound + 1):
        sum_of_letters += find_num_letters(num, file_contents)

    print("\nThe sum of the letters from ", lower_bound, " to ",
          upper_bound, " is: ", sum_of_letters, "\n")

main(sys.argv)
