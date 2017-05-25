/*
 * p15.cpp
 *
 * Zeke Reyna
 *
 * Finds the number of lattice paths. Given an nxn grid, traveling from top
 * left corner to lower right corner, along the edges.
 */

#include <iostream>
#include <string>
#define     N       20
#define     SIZE    (N+1)
using namespace std;

typedef unsigned long long ull;

static ull grid[SIZE][SIZE];

ull find_num_paths()
{
        int i, j;

        for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {

                        if (i == 0 || j == 0)
                                grid[i][j] = 1;
                        else
                                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
                }
        }

        return grid[N][N];
}

int main()
{
        ull num_paths;
        num_paths = find_num_paths();

        cout<<"\nThe number of paths to traverse the "<<N<<"x"<<N<<" grid";
        cout<<" is "<<num_paths<<"\n\n";

        return 0;
}
