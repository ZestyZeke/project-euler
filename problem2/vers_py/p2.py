### p2.py
#
# Zeke Reyna
#
# Sums fibonacci numbers under a certain bound
#!/usr/bin/env python3
import sys

def main( argv ):

    if len(argv) == 2:
        bound = int( argv[1] )
    else:
        bound = 10

    first = 1
    second = 1
    third = 0
    sum = 0

    while ( third < bound ):
        if( second % 2 == 0 ):
            sum += second

        third = first + second
        first = second
        second = third

    print( "\nThe sum of even valued fibonacci",
            " numbers under ", bound, " is ",
            sum, "\n" )

main( sys.argv )
