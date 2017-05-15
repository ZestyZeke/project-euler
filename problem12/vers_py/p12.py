### p12.py
#
# Zeke Reyna
#
# Finds the first triangular number
# that has more than the given amount
# of divisors

import sys
import math

def find_tri(x):
    return int((x * x + x) / 2)

def find_num_factors(n):

    num_factors = 1
    for i in range(2, int(math.sqrt(n))):
        power = 0

        while n % i == 0:
            n /= i
            power += 1
        num_factors *= (power + 1)

    if n > 1:
        num_factors *= 2

    return num_factors


def main(argv):

    if len(argv) == 2:
        divis = int(argv[1])
    else:
        divis = 5

    i = 1
    found = False
    while not found:
        tri = find_tri(i)
        i += 1

        curr_num_divis = find_num_factors(tri)
        if curr_num_divis > divis:
            found = True

    print ("\nThe first triangular number that has",
           " greater than ",divis," divisors is ",
           tri, "\n" )

main(sys.argv)
