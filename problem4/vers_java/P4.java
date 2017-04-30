
public class P4
{
        public static void print( Object line )
        {
                System.out.print( line );
        }

        public static int check( int i, int j )
        {
                String prod;
                String front;
                String end;
                int half_length;
                int retval;

                prod = Integer.toString( i * j );
                half_length = prod.length() / 2;

                if( prod.length() % 2 == 0 ) {
                        front = prod.substring( 0, half_length );
                        end   = prod.substring( half_length, prod.length() );
                } else {
                        front = prod.substring( 0, half_length );
                        end   = prod.substring( half_length + 1, prod.length() );
                }

                end = new StringBuilder( end ).reverse().toString();

                if( front.equals( end ) )
                        retval = i * j;
                else
                        retval = -1;
                return retval;
        }

        public static void main( String args[] )
        {
                int i, j;
                int curr_pal;
                int largest_pal;
                int lowerbound, upperbound;

                if( args.length == 2 ) {
                        upperbound = Integer.parseInt( args[1] );
                        lowerbound = Integer.parseInt( args[0] );
                } else {
                        upperbound = 1000;
                        lowerbound = 100;
                }

                largest_pal = 0;
                for( i = lowerbound; i < upperbound; i++ ) {
                        for( j = i; j < upperbound; j++ ) {

                                curr_pal = check( i, j );
                                if( curr_pal > largest_pal )
                                        largest_pal = curr_pal;
                        }
                }

                print( "\nThe largest palindrome that is the sum " );
                print( "of two products between the bounds " + lowerbound );
                print( " and " + upperbound + " is: " + largest_pal + "\n\n" );
        }
}
