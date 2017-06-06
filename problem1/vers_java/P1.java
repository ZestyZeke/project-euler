/*
 * P1.java
 *
 * Zeke Reyna
 *
 * Finds the sum of all multiples of 3 and 5 below 1000
 */

public class P1
{
        public static void main( String[] args )
        {
                int sum;
                int i;
                int bound;

                bound = 1000;

                sum = 0;
                for( i = 0; i < bound; i++ ) {
                        if( i % 3 == 0 || i % 5 == 0 )
                                sum += i;
                }

                System.out.print("\nThe sum of all multiples of 3 and 5 below");
                System.out.print(" "+bound+" is "+sum+"\n\n");
        }
}
