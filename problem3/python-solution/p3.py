### p3.py
#
# Zeke Reyna
#
# Problem 3:
# What is the largest prime factor of the number 600851475143 ?
#
# note: solves for all positive numbers other than the one given
import sys
import math

def make_list_of_facts(num):
    facts = []
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            facts.append(i)
            facts.append(num // i)
    return facts

def is_prime(f):
    retval = True
    for i in range(2, int(math.sqrt(f)) + 1):
        if f % i == 0:
            retval = False
            break
    return retval

def prune_facts(facts):
    facts = [f for f in facts if is_prime(f)]
    return facts

def find_largest_pf(num):
    pfs = make_list_of_facts(num)

    pfs = prune_facts(pfs)

    if len(pfs) == 0:
        largest = num
    else:
        largest = max(pfs)
    return largest

def main(args):
    if len(args) == 2:
        num = int(args[1])
    else:
        num = 600851475143

    largest = find_largest_pf(num)

    print("\nThe largest prime factor of the number", num,
          "is:", largest, "\n")

if __name__ == "__main__":
    main(sys.argv)
