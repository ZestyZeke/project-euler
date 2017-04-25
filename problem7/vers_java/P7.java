import java.util.ArrayList;

public class P7
{

        public static void print( Object line )
        {
                System.out.print( line );
        }

        // upper bound should be n*(ln(ln(n)) + ln(n))
        public static int find_bound( int n )
        {
                int term1, term2;
                
                term1 = (int) (n * Math.log( n ) );
                term2 = (int) (n * Math.log( Math.log( n ) ) );

                return term1 + term2;
        }

        public static void main( String args[] )
        {
                
                int i, n, j;
                int bound;
                ArrayList<Integer> nums = new ArrayList<Integer>();

                if( args.length == 1 )
                        n = Integer.parseInt( args[ 0 ] );
                else
                        n = 10001;

                bound = find_bound( n );

                // maybe bound should be inclusive?
                for( i = 2; i < bound; i++ ) {
                        nums.add( i  );
                }

                for( i = 0; i < nums.size(); i++ ) {

                        int temp_prime = nums.get( i );

                        for( j = i + 1; j < nums.size(); j++ ) {

                                if( nums.get( j ) % temp_prime == 0 ) {
                                        nums.remove( j );
                                }
                        }
                }

                print( "\n" );
                print( n + "th prime is " + nums.get( --n ) + "\n\n" );

        }
}
