### p13.py
#
# Zeke Reyna
#
# Sums 100 50-digit numbers

import sys

def main(argv):

    f = open("../num-alt.txt", "r");

    sum = 0
    for line in f:
        sum += int(line)
    f.close()

    first_digs = str(sum)[:10]
    print("\nThe sum of the 100 50-digit numbers is:\n",
          sum, "\nThe first ten digits are:\n", first_digs);

main(sys.argv)
