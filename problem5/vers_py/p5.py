### p5.py
#
# Zeke Reyna
#
# What is the smallest number that is evenly
# divisible by all of the numbers from 1 to 20?

import sys
import time

def main( argv ):
    start_time = time.time()

    if len( argv ) == 2:
        bound = int( argv[1] )
    else:
        bound = 10 # default value

    num = 3 # starting point
    isDivis = False

    while( not isDivis ):
        isDivis = True
        num += 1

        i = 2
        while( i <= bound and isDivis):
            if( num % i != 0 ):
                isDivis = False

            i += 1

    print( "\nThe smallest number that is evenly divisible by all of ",
           "the numbers from 1 to ", bound, " is ", num, "\n" )
    print( "--- %s seconds ---" % (time.time() - start_time ) )

main( sys.argv )
