/*
 * P11.java
 *
 * Zeke Reyna
 *
 * Problem 11:
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20x20 grid <20x20-grid.txt>?
 */

import java.io.*;

public class P11
{
	public static int diag1(int[][] mat)
	{
		int row, col;
		int prod, retval;

		retval = 0;
		for (row = 0; row <= mat.length - 4; row++) {
			for (col = 0; col <= mat.length - 4; col++) {
				prod  = mat[row][col] * mat[row + 1][col + 1];
				prod *= mat[row + 2][col + 2] * mat[row + 3][col + 3];
				if (prod > retval)
					retval = prod;
			}
		}
		return retval;
	}

	public static int diag2(int[][] mat)
	{
		int row, col;
		int prod, retval;

		retval = 0;
		for (row = 0; row <= mat.length - 4; row++) {
			for (col = 0; col <= mat.length - 4; col++) {
				prod  = mat[row][col + 3] * mat[row + 1][col + 2];
				prod *= mat[row + 2][col + 1] * mat[row + 3][col];
				if (prod > retval)
					retval = prod;
			}
		}
		return retval;
	}

	public static int horiz(int[][] mat)
	{
		int row, col;
		int prod, retval;

		retval = 0;
		for (row = 0; row <= mat.length - 1; row++) {
			for (col = 0; col <= mat.length - 4; col++) {
				prod  = mat[row][col] * mat[row][col + 1];
				prod *= mat[row][col + 2] * mat[row][col + 3];
				if (prod > retval)
					retval = prod;
			}
		}
		return retval;
	}

	public static int vert(int[][] mat)
	{
		int row, col;
		int prod, retval;

		retval = 0;
		for (row = 0; row <= mat.length - 1; row++) {
			for (col = 0; col <= mat.length - 4; col++) {
				prod  = mat[row][col] * mat[row][col + 1];
				prod *= mat[row][col + 2] * mat[row][col + 3];
				if (prod > retval)
					retval = prod;
			}
		}
		return retval;
	}

	public static int[][] process_file()
	{
		int[][] mat = new int[20][20];
		try {
			String line;
			BufferedReader in = new BufferedReader(new FileReader("../20x20-grid.txt"));

			int row = 0;
			while ((line = in.readLine()) != null) {
				int col = 0;
				for (String num : line.split(" ")) {
					mat[row][col] = Integer.parseInt(num);
					col++;
				}
				row++;
			}
		} catch (IOException e) {
			System.out.println("error reading file");
		}
		return mat;
	}

	public static void main(String args[])
	{
		int largest_adj, temp;

		int[][] mat = process_file();

		largest_adj = diag1(mat);

		temp = diag2(mat);
		if (temp > largest_adj) largest_adj = temp;

		temp = horiz(mat);
		if (temp > largest_adj) largest_adj = temp;

		temp = vert(mat);
		if (temp > largest_adj) largest_adj = temp;

		System.out.print("\nThe largest product of 4 adjacent numbers in a line in");
		System.out.print(" 20x20-grid.txt is "+largest_adj+"\n\n");
	}
}
