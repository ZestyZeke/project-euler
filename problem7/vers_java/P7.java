import java.util.ArrayList;

public class P7
{

        public static void print( Object line )
        {
                System.out.print( line );
        }

        public static void main( String args[] )
        {
                
                ArrayList<Integer> nums = new ArrayList<Integer>();
                int i, n, j;
                int bound;

                if( args.length == 1 )
                        n = Integer.parseInt( args[ 0 ] );
                else
                        n = 10001;

                bound = (int) (n * Math.log( n ));
                bound += (n * Math.log( Math.log( n ) )); 
                // upper bound should be n*(ln(ln(n)) + ln(n))

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
