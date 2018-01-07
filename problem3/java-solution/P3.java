/*
 * P3.java
 *
 * Zeke Reyna
 *
 * Problem 3:
 * What is the largest prime factor of the number 600851475143 ?
 *
 * note: Solves for all numbers that are within the bounds of
 * 'long'
 */
import java.util.ArrayList;

public class P3
{

        public static final long NOT_PF = 1;

        public static long find_flr_sqrt(long num)
        {
                long i;
                for (i = 2; i * i <= num; i++)
                        ;
                return --i;
        }

        public static ArrayList<Long> make_list_of_facts(long num)
        {
                ArrayList<Long> facts = new ArrayList<Long>();
                long i;
                long bound = find_flr_sqrt(num);

                for (i = 2; i <= bound; i++) {
                        if (num % i == 0) {
                                facts.add(i);
                                facts.add(num / i);
                        }
                }
                return facts;
        }

        public static boolean is_prime(long l)
        {
                long i;
                boolean retval = true;
                for (i = 2; i <= find_flr_sqrt(l); i++) {
                        if (l % i == 0) {
                                retval = false;
                                break;
                        }
                }
                return retval;
        }

        public static void prune_facts(ArrayList<Long> facts)
        {
                int i;
                for (i = 0; i < facts.size(); i++) {
                        if (!is_prime(facts.get(i)))
                                facts.set(i, NOT_PF);
                }
        }

        public static long find_max(ArrayList<Long> pfs)
        {
                long max = 0;
                for (long l : pfs) {
                        if (l > max)
                                max = l;
                }
                return max;
        }

        public static long find_largest_pf(long num)
        {
                ArrayList<Long> pfs;

                pfs = make_list_of_facts(num);

                prune_facts(pfs);

                long largest = find_max(pfs);
                if (largest == 1)
                        largest = num;
                return largest;
        }

        public static void main(String args[])
        {
                long num, largest;
		num = (args.length == 1) ? Long.parseLong(args[0]) : 600851475143L;

                largest = find_largest_pf(num);

                System.out.print("\nThe largest prime factor of the number "+num);
                System.out.print(" is: "+largest+"\n\n");
        }
}
