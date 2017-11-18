/*
 * P6.java
 *
 * Problem 6:
 * Find the difference between the sum of the squares of the first n
 * natural numbers and the square of the sum of the first n natural
 * numbers.
 */

public class P6
{
        public static int sqr(int n)
        {
                return n * n;
        }

        public static int triangle(int n)
        {
                return (sqr(n) + n) / 2;
        }

        /*
         * Polynomial expression for
         * sum of first n squares
         */
        public static int sum_of_squares(int n)
        {
                return n * (n + 1) * (2 * n + 1) / 6;
        }

        /*
         * nth triangular number is equal to sum of first n
         * natural numbers
         */
        public static int square_of_sum(int n)
        {
                int triangle;
                triangle = (sqr(n) + n) / 2;
                return sqr(triangle);
        }

        public static int difference(int n)
        {
                int diff;
                diff = sum_of_squares(n) - square_of_sum(n);
                if (diff < 0)
                        diff *= -1;
                return diff;
        }

        public static void main(String args[])
        {
                int n;
                int answer;
                if (args.length == 1)
                        n = Integer.parseInt(args[0]);
                else
                        n = 10;

                answer = difference(n);

                System.out.format("\nThe difference between the sum of the");
                System.out.format(" squares and the square of the sum of the");
                System.out.format(" first %d natural numbers is: ", n);
                System.out.format("%d\n\n", answer);
        }
}
