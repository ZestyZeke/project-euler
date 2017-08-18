/*
 * P3.java
 *
 * Zeke Reyna
 *
 * Problem 4:
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

public class P4
{
        public static int set_lower(int digits)
        {
                int lower = 1;
                for (int i = 1; i < digits; i++)
                        lower *= 10;
                return lower;
        }

        public static int set_upper(int digits)
        {
                int upper = 1;
                for (int i = 0; i < digits; i++)
                        upper *= 10;
                return upper;
        }

        public static int check_if_prod_is_pal(int first_term, int second_term)
        {
                int product, flipped, temp;
                product = first_term * second_term;
                flipped = 0;
                temp = product;

                while (temp > 0) {
                        flipped *= 10;
                        flipped += temp % 10;
                        temp /= 10;
                }

                if (product != flipped)
                        product = 0;
                return product;
        }

        public static int find_largest_pal(int lower, int upper)
        {
                int i, j;
                int cur_pal;
                int largest_pal = 0;
                for (i = lower; i < upper; i++) {
                        for (j = i; j < upper; j++) {
                                cur_pal = check_if_prod_is_pal(i, j);
                                if (cur_pal > largest_pal)
                                        largest_pal = cur_pal;
                        }
                }
                return largest_pal;
        }

        public static void main(String args[])
        {
                int largest_pal = 0;
                int num_digits;
                if (args.length == 1)
                        num_digits = Integer.parseInt(args[0]);
                else
                        num_digits = 3; // default

                int lower_bound, upper_bound;
                lower_bound = set_lower(num_digits);
                upper_bound = set_upper(num_digits);

                largest_pal = find_largest_pal(lower_bound, upper_bound);

                System.out.print("\nThe largest palindrome that is made from the product of");
                System.out.println(" two "+num_digits+"-digit numbers is: "+largest_pal+"\n");

        }
}
