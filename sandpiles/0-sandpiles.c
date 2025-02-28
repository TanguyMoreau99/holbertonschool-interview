#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * compute_sandpiles - Sum and stabilize two 3x3 sandpiles
 * @pile1: First 3x3 sandpile
 * @pile2: Second 3x3 sandpile
 */

void compute_sandpiles(int pile1[3][3], int pile2[3][3])
{
	int row = 0;
	int col = 0;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			pile1[row][col] += pile2[row][col];
		}
	}

	/* Continuously topple until stability is achieved */
	while (is_unstable(pile1) == 0)
	{
		printf("=\n");
		display_grid(pile1);
		stabilize_pile(pile1);
	}
}

/**
 * is_unstable - Checks if any cell in a grid exceeds 3
 * @pile: Sandpile to check
 *
 * Return: 0 if unstable, 1 otherwise
 */

int is_unstable(int pile[3][3])
{
	int row = 0;
	int col = 0;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (pile[row][col] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * stabilize_pile - Reduces cells greater than 3 by distributing sand
 * @pile: Sandpile to stabilize
 */

void stabilize_pile(int pile[3][3])
{
	int row = 0;
	int col = 0;
	int overflow[3][3];

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			overflow[row][col] = (pile[row][col] > 3) ? 1 : 0;
		}
	}
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (overflow[row][col] == 1)
			{
				pile[row][col] -= 4;
				if (row > 0)
				{
					pile[row - 1][col] += 1;
				}
				if (row < 2)
				{
					pile[row + 1][col] += 1;
				}
				if (col > 0)
				{
					pile[row][col - 1] += 1;
				}
				if (col < 2)
				{
					pile[row][col + 1] += 1;
				}
			}
		}
	}
}

/**
 * display_grid - Outputs a 3x3 sandpile to the console
 * @grid: Grid to display
 */
static void display_grid(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (col)
				printf(" ");
			printf("%d", grid[row][col]);
		}
		printf("\n");
	}
}
