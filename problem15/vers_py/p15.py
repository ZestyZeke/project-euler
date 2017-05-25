### p15.py
#
# Zeke Reyna
#
# Finds the number of lattice paths from a
# nxn grid, starting at top left, ending at
# bottom right

import sys

def construct_grid(n):

    row_size, col_size = n, n
    grid = [[0 for col in range(col_size)] for row in range(row_size)]

    return grid

def find_num_paths(n):

    grid = construct_grid(n)

    for row in range(n):
        for col in range(n):

            if row == 0 or col == 0:
                grid[row][col] = 1
            else:
                grid[row][col] = grid[row-1][col] + grid[row][col-1]

    return grid[n-1][n-1]

def main(argv):

    if len(argv) == 2:
        n = int(argv[1])
    else:
        n = 2 # default

    num_paths = find_num_paths(n+ 1) # give one extra, bc num_sqrs != num_intersections

    print("\nThe number of lattice paths for the ",n,"x",n," grid ",
          "is ", num_paths,"\n")

main(sys.argv)
