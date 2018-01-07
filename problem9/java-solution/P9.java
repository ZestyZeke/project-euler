/*
 * P9.java
 *
 * Zeke Reyna
 *
 * Problem 9:
 * There exists one pythagorean triplet such that a + b + c = sum.
 * Find the product a * b * c.
 */

import java.lang.Math;

public class P9
{
	public static int find_c(int a, int b)
	{
		int c = (int) Math.sqrt((a*a) + (b*b));
		if (c*c != a*a + b*b)
			c = -1;
		return c;
	}

	public static void main(String args[])
	{
		int sum;
		int a, b, c;
		int product;
		boolean found;

		sum = (args.length == 1) ? Integer.parseInt(args[0]) : 1000;

		product = -1;
		found = false;
		for (a = 1; a < sum && !found; a++) {
			for (b = 1; b < sum && !found; b++) {
				c = find_c(a, b);
				if (c != -1 && (a + b + c) == sum) {
					product = a * b * c;
					found = true;
				}
			}
		}

		System.out.print("\nThe product of the pythagorean triplets ");
		System.out.print("that sum to "+sum+" is "+product+"\n\n");
	}
}
