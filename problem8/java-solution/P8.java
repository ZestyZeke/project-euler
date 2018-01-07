/*
 * P8.java
 *
 * Zeke Reyna
 *
 * Problem 8:
 * Find the thirteen digits in the 100-digit number <../100-digit-number.txt>
 * that have the greatest product. What is the value of this product?
 */

import java.util.*;
import java.io.*;

public class P8
{
	public static long find_product(String digits, int adj)
	{
		long product = 1;
		for (int i = 0; i < adj; i++) {
			char temp = digits.charAt(i);
			product *= Character.getNumericValue(temp);
		}
		return product;
	}

	public static void main(String args[])
	{
		int i;
		int adj;
		long largest_product, curr_product;
		String line;

		adj = (args.length == 1) ? Integer.parseInt(args[0]) : 13;

		try {
			BufferedReader br = new BufferedReader(
					new FileReader("../100-digit-number.txt"));
			line = br.readLine();
			br.close();
		} catch (IOException e) {
			System.out.println(e);
			return;
		}

		largest_product = -1;
		for (i = 1; i + adj <= line.length(); i++) {
			curr_product = find_product(line.substring(i, i + adj), adj);
			if (curr_product > largest_product)
				largest_product = curr_product;
		}

		System.out.print("\nThe largest product of the "+adj+" adjacent");
		System.out.print(" digits in 100-digit-number.txt is ");
		System.out.print(largest_product+"\n\n");
	}
}
