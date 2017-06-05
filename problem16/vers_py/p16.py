### p16.py
#
# Zeke Reyna
#
# Power Digit Sum: What is the sum of the digits
# of the number 2^(1000)?
#
# For example, 2^15 = 32768
# and the sum of its digits is 26.

import sys

def main(argv):

    if len(argv) == 2:
        limit = int(argv[1])
    else:
        limit = 15 # default

    num = 2
    for i in range(1, limit):
        num *= 2

    sum_digits = sum(map(int, str(num)))
    print("\nThe sum of the digits of 2^", limit,
          " is:", sum_digits, "\n")


main(sys.argv)
