/*
 * P10.java
 *
 * Zeke Reyna
 *
 * Problem 10:
 * Find the sum of all the primes below two million.
 */

import java.util.ArrayDeque;
import java.util.Queue;
import java.lang.Math.*;

public class P10
{
	public static Queue<Integer> generate_primes(int bound)
	{
		Queue<Integer> primes = new ArrayDeque<Integer>();
		for (int num = 2; num < bound; num++) {
			boolean isPrime = true;
			for (Integer p : primes) {
				if (num % p == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime)
				primes.add(num);
		}
		return primes;
	}

	public static long sum_primes(Queue<Integer> primes)
	{
		long sum = 0;
		for (Integer num : primes)
			sum += num;
		return sum;
	}

	public static void main(String args[])
	{
		int n;
		long sum;
		Queue<Integer> primes;

		n = (args.length == 1) ? Integer.parseInt(args[0]) : 2000000;

		primes = generate_primes(n);
		sum = sum_primes(primes);

		System.out.print("\nThe sum of the primes below ");
		System.out.print(n + " is " + sum + "\n\n");
	}
}
