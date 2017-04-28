import java.util.ArrayList;

public class P10
{
        public static void print( Object line )
        {
                System.out.print( line );
        }

        public static void main( String args[] )
        {
                int i, j;
                int bound;
                int temp_prime;
                long sum;
                ArrayList<Integer> primes = new ArrayList<>();

                if( args.length == 1 )
                        bound = Integer.parseInt( args[0] );
                else
                        bound = 10;

                for( i = 2; i < bound; i++ )
                        primes.add( i );

                for( i = 0; i < primes.size(); i++ ) {

                        temp_prime = primes.get( i );

                        for( j = i + 1; j < primes.size(); j++ ) {

                                if( primes.get( j ) % temp_prime == 0 )
                                        primes.remove( j );
                        }
                }


                //print( "Primes are \n");
                sum = 0;
                for( i = 0; i < primes.size(); i++ ) {
                        sum += primes.get( i );
                        //print( primes.get( i ) + "\n" );
                }

                print( "\nThe sum of the primes below " + bound );
                print( " is " + sum + "\n\n" );
        }
}
