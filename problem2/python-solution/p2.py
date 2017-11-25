### p2.py
#
# Zeke Reyna
#
# Problem 2:
# By considering the terms in the Fibonacci sequennce whose values do not
# exceed four million, find the sum of the even-valued terms.
#
# note: solves for positive bounds other than four million

import sys

def main(args):
    if len(args) == 2:
        bound = int(args[1])
    else:
        bound = 4000000 # default

    first  = 1
    second = 1
    sums   = 0

    while second < bound:
        if second % 2 == 0:
            sums += second

        third = first + second
        first = second
        second = third

    print("\nThe sum of the even-valued Fibonacci numbers under",
          "the bound", bound, "is:", sums, "\n")

if __name__ == "__main__":
    main(sys.argv)
