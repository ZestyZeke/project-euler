### p14.py
#
# Zeke Reyna
#
# Finds the starting number with the largest
# Collatz sequence under a given bound.

import sys

def search_for_chains(bound):

    largest_num = 0
    largest_seq = 0
    for i in range(2, bound):

        temp_seq = 0
        temp_num = i
        while temp_num != 1:

            if temp_num % 2 == 0:
                temp_num /= 2
            else:
                temp_num = 3 * temp_num + 1

            temp_seq += 1

        if temp_seq > largest_seq:
            largest_seq = temp_seq
            largest_num = i

    nums = [largest_num, largest_seq]
    return nums


def main(argv):

    if len(argv) == 2:
        bound = int(argv[1])
    else:
        bound = 10

    largest = search_for_chains(bound)
    num = largest[0]
    seq = largest[1]

    print("\nThe starting number with the largest Collatz",
          " sequence below ", bound," is ", num, " and the",
          " length of its sequence is ", seq, "\n")

main(sys.argv)
