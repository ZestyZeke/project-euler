/*
 * P14.java
 *
 * Zeke Reyna
 *
 * Finds the starting number with the largest Collatz
 * sequence under a given bound
 */

import static java.lang.System.out;
public class P14
{

        public static long[] search_for_chains(int bound)
        {
                long largest_num, largest_seq;
                long temp_num, temp_seq;
                long i;
                long[] nums;

                largest_seq = 0;
                largest_num = 0;
                for (i = 2; i < (long) bound; i++) {

                        temp_seq = 0;
                        for (temp_num = i; temp_num != 1; temp_seq++) {

                                if (temp_num % 2 == 0)
                                        temp_num /= 2;
                                else
                                        temp_num = 3 * temp_num + 1;
                        }

                        if (temp_seq > largest_seq) {
                                largest_seq = temp_seq;
                                largest_num = i;
                        }
                }
                nums = new long[] {largest_num, largest_seq};
                return nums;
        }

        public static void main(String args[])
        {
                int bound;
                long[] nums;

                if (args.length == 1)
                        bound = Integer.parseInt(args[0]);
                else
                        bound = 10; //default

                nums = search_for_chains(bound);

                out.printf("\nThe starting number with the largest Collatz ");
                out.printf("sequence below %d is %d and the ", bound, nums[0]);
                out.printf("length of its sequence is %d\n\n", nums[1]);

        }
}
