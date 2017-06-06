### p1.py
#
# Zeke Reyna
# 
# This function sums all the multiples of 3 and 5
# below BOUND

import sys

def main(argv):
    if len(argv) == 2:
        bound = int(argv[1])
    else:
        bound = 10

    sum = 0
    for i in range(1, bound):
        if i % 3 == 0 or i % 5 == 0:
            sum += i

    print("\nThe sum of all multiples of 3 and 5 below ", bound, " is ", sum , "\n" )



main(sys.argv)
