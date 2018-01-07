/*
 * P7.java
 *
 * Zeke Reyna
 *
 * Problem 7:
 * What is the 10001st prime number?
 */

import java.util.ArrayList;

public class P7
{
	public static int find_bound(int n)
	{
		int term1, term2;
		term1 = (int) (n * Math.log(n));
		term2 = (int) (n * Math.log(Math.log(n)));
		return term1 + term2;
	}

	public static void main(String args[])
	{
		int i, n, j;
		int bound;
		ArrayList<Integer> nums = new ArrayList<Integer>();

		n = (args.length == 1) ? Integer.parseInt(args[0]) : 10001;

		bound = find_bound(n);

		for (i = 2; i < bound; i++)
			nums.add(i);

		for (i = 0; i < nums.size(); i++) {
			int temp_prime = nums.get(i);
			for (j = i + 1; j < nums.size(); j++) {
				if (nums.get(j) % temp_prime == 0)
					nums.remove(j);
			}
		}

		System.out.println();
		System.out.println("The" + n + "th prime number is " + nums.get(--n) + "\n");
	}
}
