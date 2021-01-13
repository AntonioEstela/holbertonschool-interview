#include "sandpiles.h"
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * add_sandpiles - function that adds a 3x3 sandpile
 * @grid1: a 3x3 matrix
 * @grid2: a 3x3 matrix
 * Return: 1 if the sandpile is unstable otherwhise will return 0
 */
int add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int x = 0;
	int y = 0;
	int isUnstable = 0;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
			grid2[x][y] = 0;

			if (grid1[x][y] > 3)
				isUnstable = 1;
		}
	}

	return (isUnstable == 0 ? 0 : 1);
}
/**
 * toppling_sandpiles - function that topples a sandpile
 * @grid1: a 3x3 matrix
 * @grid2: a 3x3 matrix
 */
void toppling_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int x = 0;
	int y = 0;

	printf("=\n");
	print_grid(grid1);

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] > 3)
			{
				grid1[x][y] -= 4;

				if (x + 1 < 3)
					grid2[x + 1][y]++;

				if (x - 1 >= 0)
					grid2[x - 1][y]++;

				if (y + 1 < 3)
					grid2[x][y + 1]++;

				if (y - 1 >= 0)
					grid2[x][y - 1]++;
			}

		}
	}
}
/**
 * sandpiles_sum - function that sums two sandpiles
 * @grid1: first grid of sandpiles
 * @grid2: second grid of sandpiles
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int isUnstable = 0;

	isUnstable = add_sandpiles(grid1, grid2);
	while (isUnstable != 0)
	{
		toppling_sandpiles(grid1, grid2);
		isUnstable = add_sandpiles(grid1, grid2);
	}

}
