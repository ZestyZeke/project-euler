### p10.py
#
# Zeke Reyna
#
# Sums the primes under a given bound

import sys

def generate_primes( primes, bound ):

    for i in range(2, bound):

        isPrime = True
        for j in primes:
            if i % j == 0:
                isPrime = False
                break

        if isPrime:
            primes.append( i )

def sum_primes( primes ):

    sum = 0
    for i in primes:
        sum += i

    return sum

def main( argv ):

    if len(argv) == 2:
        bound = int(argv[1])
    else:
        bound = 10

    primes = []
    generate_primes( primes, bound )
    sum = sum_primes( primes )

    print("The sum of the primes below ",
          bound," is ",sum,"\n")

main(sys.argv)
