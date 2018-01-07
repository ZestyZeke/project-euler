/*
 * P2.java
 *
 * Zeke Reyna
 *
 * Problem 2:
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 *
 * note: solves for positive bounds other than four million that do not exceed
 * the bounds of 'int'
 */

public class P2
{
        public static void main(String args[])
        {
                int bound;
                int first, second;
                long sum;
		int bound = (args.length == 1) ? Integer.parseInt(args[0]) : 4000000;

                first  = 1;
                second = 1;
                sum    = 0;

                while (second < bound) {
                        if (second % 2 == 0)
                                sum += (long) second;

                        int third = first + second;
                        first = second;
                        second = third;
                }

                System.out.print("\nThe sum of the even-valued Fibonacci numbers under ");
                System.out.print("the bound "+bound+" is: "+sum+"\n\n");
        }
}
