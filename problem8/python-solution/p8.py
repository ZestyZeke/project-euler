### p8.py
#
# Zeke Reyna
#
# Problem 8:
# Find the thirteen digits in the 100-digit number <../100-digit-number.txt>
# that have the greatest product. What is the value of this product?

import sys

def find_product(digits, adj):
    product = 1
    for i in range(0, adj):
        product *= int(digits[i])
    return product

if __name__ == "__main__":
    if len(sys.argv) == 2:
        adj = int(sys.argv[1])
    else:
        adj = 13

    f = open("../100-digit-number.txt", "r")
    number = f.readline()
    f.close()

    largest_product = -1
    for i in range(0, len(number) - adj):
        curr_product = find_product(number[i:i + adj], adj)
        if curr_product > largest_product:
            largest_product = curr_product

    print ("\nThe largest product of the", adj, "adjacent digits in",
           "100-digit-number.txt is", largest_product, "\n")
