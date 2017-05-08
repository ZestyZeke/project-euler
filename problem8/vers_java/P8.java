/*
 * P8.java
 *
 * Zeke Reyna
 *
 * Reads in a large text file that represents an int, the finds
 * the adjacent digits that form the largest product.
 *
 * In this specific case, the goal is a 100 digit number, and to
 * find the 13 adjacent digits that form the largest product.
 */

import java.util.*;
import java.io.*;

public class P8
{
        public static void print( Object o )
        {
                System.out.print( o );
        }

        public static long find_product( String digits, int adj )
        {
                long product;
                int i;
                char temp;

                product = 1;
                for( i = 0; i < adj; i++ ) {
                        temp = digits.charAt( i );
                        product *= Character.getNumericValue( temp );
                }

                return product;
        }

        public static void main( String args[] )
        {
                int i;
                int adj;
                long largest_product, curr_product;
                String line;

                if( args.length == 1 )
                        adj = Integer.parseInt( args[0] );
                else
                        adj = 4; // default case

                try { //ugh, try catch blocks.
                        BufferedReader br = new BufferedReader( new FileReader("../num.txt"));
                        line = br.readLine();
                        br.close();
                } catch( FileNotFoundException e) {
                        System.out.println( e );
                        return;
                } catch( IOException e ) {
                        System.out.println( e );
                        return;
                }

                largest_product = -1;
                // not so sure about bounds. could subtract 1 from (i + adj)
                for( i = 1; i + adj <= line.length(); i++ ) {

                        curr_product = find_product( line.substring( i, i + adj ), adj );

                        if( curr_product > largest_product )
                                largest_product = curr_product;
                }

                print( "\nThe largest product of the "+adj+" adjacent digits in num.txt" );
                print( " are "+largest_product+"\n\n" );

        }
}
