/*
 * p15.c
 *
 * Zeke Reyna
 *
 * Lattice Paths: Starting in the top corner of an nxn grid, how
 * many paths are there to the bottom right corner.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define		N		20
#define		SIZE		(N+2) // SIZE = N + 1

typedef unsigned long long ull;

/*
 * starts at (0,0) and grows to right and downwards
 */
struct pos {
	ull row;
	ull col;
};

static ull grid[SIZE][SIZE];

/*
 * Basic structure of 3x3 grid:
 * 1110
 * 1110
 * 1120
 * 0000
 */
void construct_grid()
{
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {

			if (i == N && j == N)
				grid[i][j] = 2;
			else if (i == (SIZE - 1) || j == (SIZE - 1))
				grid[i][j] = 0;
			else
				grid[i][j] = 1;
		}
	}
}

ull find_paths(struct pos curr)
{
	ull grid_val;
	grid_val = grid[curr.row][curr.col];

	if (grid_val == 2)
		return 1;
	if (grid_val == 0)
		return 0;

	struct pos down, right;
	down.row  = curr.row + 1;
	down.col  = curr.col;
	right.row = curr.row;
	right.col = curr.col + 1;

	return find_paths(down) + find_paths(right);
}

int main()
{
	ull n;
	ull num_paths;
	struct pos starting_point;

	construct_grid();

	/*for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%llu ", grid[i][j]);
		}
		printf("\n");
	}*/

	starting_point.row = 0;
	starting_point.col = 0;

	num_paths = find_paths(starting_point);

	n = N;
	printf("\nThe number of paths to traverse the %llux%llu grid", n, n);
	printf(" is %llu\n\n", num_paths);
	return 0;
}
