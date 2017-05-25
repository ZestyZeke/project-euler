/*
 * P15.java
 *
 * Zeke Reyna
 *
 * Lattice Paths: Starting in the top corner of an nxn grid, how
 * many paths are there to the bottom right corner.
 */

import java.math.*;
public class P15
{
        /*
         * (n)*...*(1)
         */
        public static BigInteger factorial(int n)
        {
                BigInteger retval;
                int i;

                retval = BigInteger.ONE;
                for (i = 1; i <= n; i++)
                        retval = retval.multiply(BigInteger.valueOf(i));

                return retval;
        }

        /*
         * (2n)*...*(n+1)
         */
        public static BigInteger half_fact(int n)
        {
                BigInteger retval;
                int i;

                retval = BigInteger.ONE;
                for (i = 2 * n; i > n; i--)
                        retval = retval.multiply(BigInteger.valueOf(i));

                return retval;
        }

        /*
         * (2n)!/(n!)^2 = (2n)*...*(n+1)/n!
         */
        public static BigInteger find_lattice_paths(int n)
        {
                return half_fact(n).divide(factorial(n));
        }

        public static void main(String args[])
        {
                int n;
                BigInteger num_paths;

                if (args.length == 1)
                        n = Integer.parseInt(args[0]);
                else
                        n = 2; // default

                num_paths = find_lattice_paths(n);

                System.out.printf("\nThe number of paths for the %dx%d grid is", n, n);
                System.out.printf(" %s\n\n", num_paths.toString());
        }
}
