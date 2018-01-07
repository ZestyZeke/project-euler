### p9.py
#
# Zeke Reyna
#
# Problem 9:
# There exists one pythagorean triplet such that a + b + c = sum.
# Find the product a * b * c.

import sys
import math

def find_c(a, b):
    c = int(math.sqrt(a*a + b*b))
    if c*c != a*a + b*b:
        c = -1
    return c

if __name__ == "__main__":
    if len(sys.argv) == 2:
        sum = int(sys.argv[1])
    else:
        sum = 1000

    product = -1
    for a in range(1, sum):
        for b in range(1, sum):
            c = find_c(a, b)
            if c != -1 and (a + b + c) == sum:
                product = a * b * c
                break
        if product > 0:
            break

    print("\nThe product of the pythagorean triplets that sum",
          "to", sum, "is", product, "\n")
