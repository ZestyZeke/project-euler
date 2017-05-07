### p7.py
#
# Zeke Reyna
#
# Finds nth prime

import sys
import math

def generate_upper( n ):
    term1 = n * math.log( n )
    term2 = n * ( math.log( math.log( n ) ) )
    return int( term1 + term2 )

def generate_nums( nums, bound ):
    for i in range(2, bound):
        nums.append( i )

def isFactor( num, fac ):
    if num == fac:
        return False
    if num % fac == 0:
        return True
    else:
        return False

def sieve( nums, n ):

    i = 0
    temp_n = 1

    while temp_n <= n and i < len(nums):
        temp_prime = nums[i]

        nums[:] = [x for x in nums if not isFactor( x, temp_prime )]

        i += 1
        temp_n += 1

    return nums[n - 1]


def main( argv ):

    if len(argv) == 2:
        n = int( argv[1] )
    else:
        n = 7

    upperbound = generate_upper( n )

    nums = []
    generate_nums( nums, upperbound )

    nth_prime = sieve( nums, n )

    print( "\nThe ",n,"th prime number is ",nth_prime,"\n" );

main( sys.argv );
