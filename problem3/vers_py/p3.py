### p3.py
#
# Zeke Reyna
#
# Finds the greatest prime divisor of a number
import sys

def main( argv ):

    if len(argv) == 2:
        num = int( argv[1] )
    else:
        num = 99

    prime_factors = []
    prime_factors.append( 2 )

    for i in range(2, num):

        if( num % i != 0):
            continue

        isPrime = 1
        for j in prime_factors:
            if i % j == 0:
                isPrime = 0

        if isPrime:
            prime_factors.append( i )

    largest_prime = prime_factors[ -1 ]

    print( "\nThe largest prime factor of ",
          num, " is ", largest_prime, "\n" )


main( sys.argv )
