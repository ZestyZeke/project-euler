### p9.py
#
# Zeke Reyna
#
# There exists one pythagorean triplet such that a + b + c = sum.
# Find the product a*b*c.
# For reference, 3^2 + 4^2 = 5^2

import sys
import math

def find_c( a, b ):
    c = int( math.sqrt( a*a + b*b ) )

    if c*c != a*a + b*b:
        c = -1

    return c

def main( argv ):

    if len(argv) == 2:
        sum = int(argv[1])
    else:
        sum = 12

    product = -1
    for i in range(1, sum):
        for j in range(1, sum):

            c = find_c( i, j )
            if c != -1 and (i + j + c) == sum:
                product = i * j * c
                break

        if product > 0:
            break

    print("\nThe product of the pythagorean triplets that sum",
          " to ",sum," is ",product,"\n")


main( sys.argv )
