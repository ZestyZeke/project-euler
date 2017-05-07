import static java.lang.System.out;

public class P6
{
        public static int sqr( int n )
        {
                return n * n;
        }

        public static int triangle( int n )
        {
                return (sqr(n) + n)/2;
        }

        public static int sum_of_squares( int n )
        {
                return n * (n + 1) * (2 * n + 1) / 6;
        }

        public static void main( String args[] )
        {
                int bound, answer;

                if( args.length == 1 )
                        bound = Integer.parseInt( args[0] );
                else
                        bound = 10;

                answer = sum_of_squares( bound ) - sqr( triangle( bound ) );

                if( answer < 0 )
                        answer = -1 * answer;

                out.format("\nThe difference between the sum of the squares and the"); 
                out.format(" square of the sum of the first %d natural", bound );
                out.format(" numbers is %d\n\n", answer );
        }
}
