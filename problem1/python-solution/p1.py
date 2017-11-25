"""
@file:   p1.py
@author: Ezekiel Reyna

Problem 1: Find the sum of the multiples of 3 or 5 below 1000.
"""
import sys

def main(argv):
    bound = 1000 # default
    sum = 0
    if len(argv) == 2:
        bound = int(argv[1])
    for i in range(1, bound):
        if i % 3 == 0 or i % 5 == 0:
            sum += i
    print("\nThe sum of the multiples of 3 or 5 below",
          bound, "are:", sum, "\n")

if __name__ == "__main__":
    main(sys.argv)
