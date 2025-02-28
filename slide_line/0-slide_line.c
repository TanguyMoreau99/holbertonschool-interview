#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "slide_line.h"

/**
 * slide_line - Effectue un déplacement et une fusion des éléments d'un tableau d'entiers
 * @array: pointeur vers un tableau d'entiers
 * @length: nombre d'éléments dans le tableau
 * @direction: direction du déplacement (gauche ou droite)
 *
 * Return: 1 si succès, 0 si échec
 */
int slide_line(int *array, size_t length, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		shift_left(array, length);
		combine_left(array, length);
		shift_left(array, length);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		shift_right(array, length);
		combine_right(array, length);
		shift_right(array, length);
		return (1);
	}
	return (0);
}

/**
 * shift_left - Décale tous les éléments non nuls du tableau vers la gauche
 * @array: pointeur vers un tableau d'entiers
 * @length: taille du tableau
 */
void shift_left(int *array, size_t length)
{
	size_t fill_index = 0;
	size_t search_index = 0;

	while (search_index < length)
	{
		if (array[search_index] != 0)
		{
			array[fill_index] = array[search_index];
			fill_index++;
		}
		search_index++;
	}
	while (fill_index < length)
	{
		array[fill_index] = 0;
		fill_index++;
	}
}

/**
 * shift_right - Décale tous les éléments non nuls du tableau vers la droite
 * @array: pointeur vers un tableau d'entiers
 * @length: taille du tableau
 */
void shift_right(int *array, size_t length)
{
	int fill_index = length - 1;
	int search_index = length - 1;

	while (search_index >= 0)
	{
		if (array[search_index] != 0)
		{
			array[fill_index] = array[search_index];
			fill_index--;
		}
		search_index--;
	}
	while (fill_index >= 0)
	{
		array[fill_index] = 0;
		fill_index--;
	}
}

/**
 * combine_left - Combine les éléments consécutifs et identiques du tableau en décalant vers la gauche
 * @array: pointeur vers un tableau d'entiers
 * @length: taille du tableau
 */
void combine_left(int *array, size_t length)
{
	size_t i, next;

	for (i = 0; i < length; i++)
	{
		if (array[i] == 0)
		{
			continue;
		}
		next = i + 1;
		while (next < length)
		{
			if (array[next] != 0)
			{
				if (array[i] == array[next])
				{
					array[i] += array[next];
					array[next] = 0;
				}
				break;
			}
			next++;
		}
	}
}

/**
 * combine_right - Combine les éléments consécutifs et identiques du tableau en décalant vers la droite
 * @array: pointeur vers un tableau d'entiers
 * @length: taille du tableau
 */
void combine_right(int *array, size_t length)
{
	int i, prev;

	for (i = length - 1; i > 0; i--)
	{
		if (array[i] == 0)
		{
			continue;
		}
		prev = i - 1;
		while (prev >= 0)
		{
			if (array[prev] != 0)
			{
				if (array[i] == array[prev])
				{
					array[i] += array[prev];
					array[prev] = 0;
				}
			}
			break;
		}
		prev--;
	}
}
