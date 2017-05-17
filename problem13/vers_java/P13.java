/*
 * P13.java
 *
 * Zeke Reyna
 *
 * Sums 100 50-digit numbers.
 */

import java.io.*;
import java.math.BigInteger;

public class P13
{

        public static BigInteger process()
        {
                BufferedReader rdr = null;
                String line;
                BigInteger sum;

                try {
                        rdr = new BufferedReader(new FileReader(new File("../num-alt.txt")));
                        sum = BigInteger.ZERO;

                        while ((line = rdr.readLine()) != null) {
                                sum = sum.add(new BigInteger(line));
                        }
                        rdr.close();
                        return sum;

                } catch (IOException e) {
                        System.out.println("error");
                        return BigInteger.ZERO;
                }
        }

        public static String get_first_digits(BigInteger num)
        {
                String digits;
                digits = num.toString();
                return digits.substring(0, 10);
        }

        public static void main(String args[])
        {
                BigInteger sum;
                String first_ten;

                sum = process();
                first_ten = get_first_digits(sum);

                System.out.printf("\nThe sum of the 100 50-digit numbers is:\n");
                System.out.printf("%d\n", sum);
                System.out.printf("The first ten digits are:\n");
                System.out.printf("%s\n\n", first_ten);
        }
}
