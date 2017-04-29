import static java.lang.System.out;

public class Fib
{
        public static void main(String args[] )
        {
                int first, second, third;
                int sum;
                int bound;

                if( args.length == 1 )
                        bound = Integer.parseInt( args[0] );
                else
                        bound = 10;

                first = 1;
                second = 1;
                third = 0;
                sum = 0;

                while( third < bound ) {
                        if( second % 2 == 0 )
                                sum += second;

                        third = first + second;
                        first = second;
                        second = third;
                }

                out.print("\nThe sum of even valued fibonacci terms under ");
                out.println( bound + " is " + sum + "\n");
        }
}
