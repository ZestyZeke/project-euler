### p5.py
#
# Zeke Reyna
#
# Problem 5:
# What is the smallest positive number that is evenly divisible by all of
# the numbers from 1 to 20?
import sys

def generate_divisors(bound):
    divis = []

    for num in range(1, bound + 1):
        redundant = False
        for i in range(num + 1, bound + 1):
            if (i % num == 0):
                redundant = True
                break
        if not redundant:
            divis.append(num)
    return divis

def find_first_divisible_num(divis, bound):
    num = bound
    found = False

    while not found:
        num += 1
        found = True
        for d in divis:
            if num % d != 0:
                found = False
                break
    return num

def main(args):
    if len(args) == 2:
        bound = int(args[1])
    else:
        bound = 20

    divisors = generate_divisors(bound)

    num = find_first_divisible_num(divisors, bound)

    print("\nThe smallest positive number that is divisible by all of the",
          "numbers from 1 to {} is: {}\n".format(bound, num))

if __name__ == "__main__":
    main(sys.argv)
