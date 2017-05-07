### p6.py
#
# Zeke Reyna
#
# Find the difference between the sum of the squares of the first n natural
# numbers and the square of the sum of the first n natural numbers

import sys

def sqr( n ):
    return n * n

def triangle( n ):
    return (sqr(n) + n) / 2

def sum_of_squares( n ):
    return n * (n + 1) * (2 * n + 1) / 6;

def main( argv ):

    if len(argv) == 2:
        bound = int( argv[1] )
    else:
        bound = 10

    answer = sum_of_squares( bound ) - sqr( triangle( bound ) )
    if answer < 0:
        answer = -1 * answer

    print( "\nThe difference between the sum of the squares and the",
           " square of the sum of the first ", bound, " natural num",
           "bers is ", int(answer), "\n" );

main( sys.argv )
