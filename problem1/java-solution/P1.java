/*
 * P1.java
 *
 * Zeke Reyna
 *
 * Problem 1: Find the sum of the multiples of 3 or 5 below 1000.
 */

public class P1
{
        public static void main(String args[])
        {
                long sum = 0;
                int i;
                int bound = 1000; // default
                if (args.length == 1)
                        bound = Integer.parseInt(args[0]);

                for (i = 1; i < bound; i++) {
                        if (i % 3 == 0 || i % 5 == 0)
                                sum += i;
                }

                System.out.print("\nThe sum of the multiples of 3 or 5 below "+bound);
                System.out.println(" are: "+sum+"\n");
        }
}
