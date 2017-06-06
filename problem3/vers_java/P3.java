/*
 * P3.java
 *
 * Zeke Reyna
 *
 * A simple function that finds the largest
 * prime factor of a number
 */

import java.util.*;
import java.math.*;

public class P3
{

        public static void print(Object line)
        {
                System.out.print(line);
        }

        public static BigInteger sqrt(BigInteger num)
        {
                BigInteger div = BigInteger.ZERO.setBit(num.bitLength() / 2);
                BigInteger div2 = div;

                for (;;) {
                        BigInteger temp = div.add(num.divide(div)).shiftRight(1);
                        if (temp.equals(div) || temp.equals(div2))
                                return num;
                        div2 = div;
                        div = temp;
                }
        }

        public static void main( String args[] )
        {
                BigInteger i;
                BigInteger largest_prime;
                BigInteger num;
                BigInteger bound;
                BigInteger temp;
                boolean isPrime;

                ArrayList<BigInteger> prime_factors = new ArrayList<BigInteger>();
                prime_factors.add(new BigInteger("2"));

                if (args.length == 1)
                        num = new BigInteger(args[0]);
                else
                        num = new BigInteger("100");

                //bound = num.divide(new BigInteger("2"));
                bound = sqrt(num);

                for (i = new BigInteger("2");
                    !i.equals(num.add(BigInteger.ONE));
                            i = i.add(BigInteger.ONE)) {

                        if (num.mod(i).equals(BigInteger.ZERO)) {

                                isPrime = true;
                                for (BigInteger j : prime_factors) {

                                        if (i.mod(j).equals(BigInteger.ZERO))
                                                isPrime = false;
                                }

                                if (isPrime)
                                        prime_factors.add(i);
                        }
                }

                largest_prime = prime_factors.get(prime_factors.size() - 1);

                print( "\nThe largest prime factor of " + num );
                print( " is " + largest_prime + "\n\n" );
        }
}
