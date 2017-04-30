### p4.py
#
# Zeke Reyna
#
# Finds the largest palindrome that is a product
# of two nums between two bounds
import sys

def check_if_pal( i, j ):

    prod = str( i * j )
    half_length = int( len( prod ) / 2 )

    if len( prod ) % 2 == 0:
        front = prod[ : half_length ]
        end   = prod[ half_length : ]
    else:
        front = prod[ : half_length ]
        end   = prod[ half_length +  1 : ]

    end = end[ : : -1 ]

    if front == end:
        retval = i * j
    else:
        retval = -1

    return retval


def main( argv ):

    if len(argv) == 3:
        upperbound = int( argv[2] )
        lowerbound = int( argv[1] )
    else:
        upperbound = 1000
        lowerbound = 100

    largest_pal = 0

    for i in range( lowerbound, upperbound ):
        for j in range( i, upperbound ):

            curr_pal = check_if_pal( i, j )
            if( curr_pal > largest_pal ):
                largest_pal = curr_pal

    print( "\nThe largest parlindrome ",
          "that is a sum of two products ",
          "between the bounds ", lowerbound,
          " and ", upperbound, " is ",
          largest_pal, "\n" )


main( sys.argv )
