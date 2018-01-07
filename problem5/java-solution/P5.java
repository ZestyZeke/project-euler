/*
 * P5.java
 *
 * Zeke Reyna
 *
 * Problem 5:
 * What is the smallest positive number that is evenly divisible by all of
 * the numbers from 1 to 20?
 */
import java.util.ArrayList;

public class P5
{

        public static ArrayList<Integer> generate_divisors(int bound)
        {
                ArrayList<Integer> retval = new ArrayList<Integer>();

                int num, i;
                boolean redundant;
                for (num = 1; num <= bound; num++) {
                        redundant = false;
                        for (i = num + 1; i <= bound; i++) {
                                if (i % num == 0) {
                                        redundant = true;
                                        break;
                                }
                        }
                        if (!redundant)
                                retval.add(num);
                }

                return retval;
        }

        public static long find_first_divisible_num(ArrayList<Integer> divis, int bound)
        {
                long num = (long) bound;
                boolean found = false;

                for (; !found; num++) {
                        found = true;
                        for (Integer i : divis) {
                                if (num % i != 0) {
                                        found = false;
                                        break;
                                }
                        }
                }
                return --num;
        }

        public static void main(String args[])
        {
                int bound = (args.length == 1) ? Integer.parseInt(args[0]) : 20;

                ArrayList<Integer> divisors = generate_divisors(bound);

                long num = find_first_divisible_num(divisors, bound);

                System.out.print("\nThe smallest positive number that is divisible");
                System.out.print(" by all of the numbers from 1 to "+bound+" is: ");
                System.out.println(num+"\n");
        }
}
