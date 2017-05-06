public class P5
{
        public static void print( Object line )
        {
                System.out.print( line );
        }

        public static void main( String args[] )
        {
                int i, num, bound;
                boolean isDivis;

                if( args.length == 1 )
                        bound = Integer.parseInt( args[0] );
                else
                        bound = 10;

                num = 3;
                isDivis = false;
                while( !isDivis ) {
                        isDivis = true;
                        num++;
                        for( i = 1; i <= bound; i++ ) {
                                if( num % i != 0 ) {
                                        isDivis = false;
                                        break;
                                }
                        }
                }
                print("\nThe smallest number that is evenly divisible by all of");
                print(" the numbers from 1 to "+bound+" is "+num+"\n\n");
        }
}
