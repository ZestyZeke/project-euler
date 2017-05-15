/*
 * P12.java
 *
 * Zeke Reyna
 *
 * Finds the first triangular number with more than
 * the given number of divisors
 */

import static java.lang.System.out;
public class P12
{
        public static int find_tri( int x )
        {
                return (x * x + x) / 2;
        }

        public static int find_num_factors( int num )
        {
                int i;
                int num_factors, power;

                num_factors = 1;
                for (i = 2; i < (int) Math.sqrt(num); i++) {
                        power = 0;

                        while (num % i == 0) {
                                num /= i;
                                power++;
                        }
                        num_factors *= (power + 1);
                }

                if (num > 1)
                        num_factors *= 2;

                return num_factors;
        }

        public static void main(String args[] )
        {
                int i, tri;
                int divis, curr_num_divis;

                if( args.length == 1 )
                        divis = Integer.parseInt( args[0] );
                else
                        divis = 5; // default

                for( i = 1; ; i++ ) {
                        tri = find_tri( i );

                        curr_num_divis = find_num_factors( tri );
                        if( curr_num_divis > divis )
                                break;
                }
                // do printing stuff and make func find_num_factors
                out.printf("\nThe first triangular number that has greater");
                out.printf(" than %d divisors is %d\n\n", divis, tri );
        }
}
