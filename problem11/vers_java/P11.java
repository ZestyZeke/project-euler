/*
 * P11.java
 *
 * Zeke Reyna
 *
 * This function takes a grid of numbers, and finds the largest product
 * of 4 adjacent numbers (diag/vert/horiz).
 */

import java.io.*;

public class P11
{
        public static int diag1( int[][] mat )
        {
                int row, col;
                int prod, retval;

                retval = 0;
                for( row = 0; row <= mat.length - 4; row++ ) {
                        for( col = 0; col <= mat.length - 4; col++ ) {

                                prod  = mat[row][col] * mat[row + 1][col + 1];
                                prod *= mat[row + 2][col + 2] * mat[row + 3][col + 3];

                                if( prod > retval )
                                        retval = prod;
                        }
                }
                return retval;
        }

        public static int diag2( int[][] mat )
        {
                int row, col;
                int prod, retval;

                retval = 0;
                for( row = 0; row <= mat.length - 4; row++ ) {
                        for( col = 0; col <= mat.length - 4; col++ ) {

                                prod  = mat[row][col + 3] * mat[row + 1][col + 2];
                                prod *= mat[row + 2][col + 1] * mat[row + 3][col];

                                if( prod > retval )
                                        retval = prod;
                        }
                }
                return retval;
        }

        public static int horiz( int[][] mat )
        {
                int row, col;
                int prod, retval;

                retval = 0;
                for( row = 0; row <= mat.length - 1; row++ ) {
                        for( col = 0; col <= mat.length - 4; col++ ) {

                                prod  = mat[row][col] * mat[row][col + 1];
                                prod *= mat[row][col + 2] * mat[row][col + 3];

                                if( prod > retval )
                                        retval = prod;
                        }
                }
                return retval;
        }

        public static int vert( int[][] mat )
        {
                int row, col;
                int prod, retval;

                retval = 0;
                for( row = 0; row <= mat.length - 1; row++ ) {
                        for( col = 0; col <= mat.length - 4; col++ ) {

                                prod  = mat[row][col] * mat[row][col + 1];
                                prod *= mat[row][col + 2] * mat[row][col + 3];

                                if( prod > retval )
                                        retval = prod;
                        }
                }
                return retval;
        }

        public static void process_file( int[][] mat )
        {
                try {
                        String line;
                        BufferedReader in = new BufferedReader( new FileReader("../num.txt") );

                        int row, col;
                        row = 0;
                        while( (line = in.readLine()) != null ) {

                                col = 0;
                                for( String num: line.split(" ") ) {
                                        mat[row][col] = Integer.parseInt( num );
                                        col++;
                                }
                                row++;
                        }
                } catch (IOException e) {
                        System.out.println("error reading file\n");
                        return;
                }
        }

        public static void main( String args[] )
        {
                int[][] mat = new int[20][20]; // can use a variable size array too. Maybe redefine later.
                int largest_adj, temp;

                process_file( mat );

                largest_adj = diag1( mat );

                temp = diag2( mat );
                if( temp > largest_adj )
                        largest_adj = temp;

                temp = horiz( mat );
                if( temp > largest_adj )
                        largest_adj = temp;

                temp = vert( mat );
                if( temp > largest_adj )
                        largest_adj = temp;

                System.out.print("\nThe largest product of 4 adjacent numbers in a line in");
                System.out.println(" num.txt is "+largest_adj+"\n" );

        }
}
