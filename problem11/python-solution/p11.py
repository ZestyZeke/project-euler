### p11.py
#
# Zeke Reyna
#
# Problem 11:
# What is the greatest product of four adjacent numbers in the same direction
# (up, down, left, right, or diagonal) in the 20x20 grid <20x20-grid.txt>?

import sys

def process_file():
    mat = []
    with open("../20x20-grid.txt") as f:
        for line in f:
            nums = list(map(int, line.split()))
            mat.append(nums)
    return mat

def diag1(mat):
    retval = 0
    for row in range(0, len(mat) - 3):
        for col in range(0, len(mat) - 3):
            prod  = mat[row][col] * mat[row + 1][col + 1]
            prod *= mat[row + 2][col + 2] * mat[row + 3][col + 3]
            if prod > retval:
                retval = prod
    return retval

def diag2(mat):
    retval = 0
    for row in range(0, len(mat) - 3):
        for col in range(0, len(mat) - 3):
            prod  = mat[row][col + 3] * mat[row + 1][col + 2]
            prod *= mat[row + 2][col + 1] * mat[row + 3][col]
            if prod > retval:
                retval = prod
    return retval

def horiz(mat):
    retval = 0
    for row in range(0, len(mat)):
        for col in range(0, len(mat) - 3):
            prod  = mat[row][col] * mat[row][col + 1]
            prod *= mat[row][col + 2] * mat[row][col + 3]
            if prod > retval:
                retval = prod
    return retval

def vert(mat):
    retval = 0
    for row in range(0, len(mat) - 3):
        for col in range(0, len(mat)):
            prod  = mat[row][col] * mat[row + 1][col]
            prod *= mat[row + 2][col] * mat[row + 3][col]
            if prod > retval:
                retval = prod
    return retval

if __name__ == "__main__":
    mat = process_file()

    largest_adj = diag1(mat)

    temp = diag2(mat)
    if temp > largest_adj: largest_adj = temp

    temp = horiz(mat)
    if temp > largest_adj: largest_adj = temp

    temp = vert(mat)
    if temp > largest_adj: largest_adj = temp

    print("\nThe largest product of 4 adjacent numbers in",
          "a line in 20x20-grid.txt is", largest_adj, "\n")
