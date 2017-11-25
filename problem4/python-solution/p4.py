### p4.py
#
# Zeke Reyna
#
# Problem 4:
# Find the largest palindrome made from the product of
# two 3-digit numbers.
import sys

def set_bounds(digits):
    lower = 1
    upper = 1
    for i in range(1, digits):
        lower *= 10
    for i in range(0, digits):
        upper *= 10
    bounds = [lower, upper]
    return bounds

def check_if_prod_is_pal(i, j):
    prod = i * j
    if str(prod) != str(prod)[::-1]:
        prod = 0
    return prod

def find_largest_pal(bounds):
    lower = bounds[0]
    upper = bounds[1]
    largest = 0
    for i in range(lower, upper):
        for j in range(i, upper):
            cur_pal = check_if_prod_is_pal(i, j)
            if cur_pal > largest:
                largest = cur_pal
    return largest

def main(args):
    if len(args) == 2:
        num_digits = int(args[1])
    else:
        num_digits = 3

    bounds = set_bounds(num_digits)
    largest = find_largest_pal(bounds)
    print("\nThe largest palindrome that is made from the product of",
          "two {}-digit numbers is: {}\n".format(num_digits, largest))

if __name__ == "__main__":
    main(sys.argv)
