/*
 * P8.java
 *
 * Zeke Reyna
 *
 * There exists one pythagorean triplet such that
 * a + b + c = sum. Find the product a*b*c.
 *
 * For reference: 3^2 + 4^2 = 5^2
 */

import java.lang.Math;

public class P9
{
        public static int find_c( int a, int b )
        {
                int c;

                c = (int) Math.sqrt( (a*a) + (b*b) );
                if( c*c != a*a + b*b )
                        c = -1;

                return c;
        }

        public static void main( String args[] )
        {
                int sum;
                int i, j, c;
                int product;
                boolean found;

                if( args.length == 1)
                        sum = Integer.parseInt( args[0] );
                else
                        sum = 12; // default

                product = -1;
                found = false;
                for( i = 1; i < sum && !found; i++ ) {
                        for( j = 1; j < sum && !found; j++ ) {

                                c = find_c( i, j );
                                if( c != -1 && (i + j + c) == sum ) {
                                        found = true;
                                        product = i * j * c;
                                }
                        }
                }

                System.out.format("\nThe product of the pythagorean triplets");
                System.out.format(" that sum to %d is %d\n\n", sum, product );
        }
}
