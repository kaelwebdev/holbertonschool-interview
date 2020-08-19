#include "sandpiles.h"

/**
 * print_grid_v2 - Print the grid
 * @grid: 3x3 matrix
 * Return: 1 == stable || 0 otherwise
*/
void print_grid_v2(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_3x3_sum - sums of two 3x3 matrix
 * @grid1: 3x3 matrix.
 * @grid2: 3x3 matrix.
 */
void grid_3x3_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}
	}
}

/**
 * check_stability - check if the grid is stable
 * @grid: 3x3 matrix (sandpile)
 * Return: 1 (stable) || 0 (otherwise)
*/
int check_stability(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * distributes_grains - distributes grains.
 * @grid1: 3x3 matrix (sandpile)
 * @grid2: 3x3 matrix (sandpile)
 */
void distributes_grains(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (j - 1 >= 0)
					grid2[i][j - 1]++;
				if (j + 1 < 3)
					grid2[i][j + 1]++;
				if (i - 1 >= 0)
					grid2[i - 1][j]++;
				if (i + 1 < 3)
					grid2[i + 1][j]++;
			}
		}
	}
}

/**
 * sandpiles_sum - calculate the distribution of the sand
 * @grid1: 3x3 matrix (sandpile)
 * @grid2: 3x3 matri (sandpile)
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_3x3_sum(grid1, grid2);
	while (check_stability(grid1) != 1)
	{
		print_grid_v2(grid1);
		distributes_grains(grid1, grid2);
		grid_3x3_sum(grid1, grid2);
	}
}
