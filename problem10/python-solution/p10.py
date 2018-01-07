### p10.py
#
# Zeke Reyna
#
# Problem 10:
# Find the sum of all the primes below two million.

import sys
from math import log
from collections import deque

def generate_primes(bound):
    primes = deque()
    for i in range(2, bound):
        isPrime = True
        for p in primes:
            if i % p == 0:
                isPrime = False
                break
        if isPrime:
            primes.append(i)
    return primes

if __name__ == "__main__":
    if len(sys.argv) == 2:
        n = int(argv[1])
    else:
        n = 2000000

    primes = generate_primes(n)
    ans = sum(primes)

    print ("\nThe sum of the primes below", bound,
           "is", ans, "\n")
