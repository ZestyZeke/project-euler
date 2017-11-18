"""
@file:   p6.py
@author: Ezekiel Reyna

Problem 6:
Find the difference between the sum of the squares of the first n
natural numbers and the square of the sum of the first n natural
numbers.
"""
import sys

def sum_of_squares(n):
    """
    Polynomial expression for
    sum of first n squares
    """
    return n * (n + 1) * (2 * n + 1) / 6;

def sqr(n):
    """
    """
    return n * n

def square_of_sum(n):
    """
    nth triangular number is equal to sum of
    first n natural numbers
    """
    triangle = (sqr(n) + n) / 2;
    return sqr(triangle)

def difference(n):
    """
    """
    diff = sum_of_squares(n) - square_of_sum(n)
    if diff < 0:
        diff *= -1
    return int(diff)

def main(argv):
    """
    """
    if len(argv) == 2:
        n = int(argv[1])
    else:
        n = 10 # default

    answer = difference(n)

    print ("\nThe difference between the sum of the squares",
           "and the square of the sum of the first", n,
           "natural numbers is:", answer, "\n")

if __name__ == "__main__":
    main(sys.argv)
