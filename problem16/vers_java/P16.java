/*
 * P16.java
 *
 * Zeke Reyna
 *
 * Power Digit Sum: What is the sum of the digits
 * of the number 2^(1000) ?
 *
 * For example, 2^15 = 32768
 * and the sum of its digits is 26.
 */

import java.math.BigInteger;
public class P16
{

        public static void main(String args[])
        {
                int limit;

                if (args.length == 1)
                        limit = Integer.parseInt(args[0]);
                else
                        limit = 15; // default

                BigInteger two = new BigInteger("2");
                BigInteger num = two;
                int i = 0;

                while (++i < limit)
                        num = num.multiply(two);

                long sum = 0;
                String rep = num.toString();
                for(char c : rep.toCharArray()) {
                        sum += c - '0';
                }

                System.out.printf("\nThe sum of the digits of 2^%d is: ", limit);
                System.out.printf("%d\n\n", sum);
        }
}
