### p8.py
#
# Zeke Reyna
#
# Reads in a text file and gives the largest product
# of the n adjacent digits in the text.

import sys

def find_product( digits, adj ):

    product = 1
    for i in range( 0, adj ):
        product *= int(digits[ i ])

    return product

def main( argv ):

    if len(argv) == 2:
        adj = int( argv[1] )
    else:
        adj = 4

    f = open( '../num.txt', 'r' )
    number = f.readline() # should be one line long
    f.close()

    largest_product = -1 # bounds?
    for i in range( 0, len(number) - adj ):

        curr_product = find_product( number[i:i+adj], adj )

        if curr_product > largest_product:
            largest_product = curr_product

    print("\nThe largest product of the ", adj, " adjacent digits",
          " in num.txt are ", largest_product, "\n" )


main(sys.argv)
