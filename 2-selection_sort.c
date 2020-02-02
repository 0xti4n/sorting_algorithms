#include "sort.h"

/**
 * selection_sort - Entry point
 * @array: the list to sort.
 * @size: the size of the array.
 * Return: Nothin.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, cM;

	for (i = 0; i < size - 1; i++)
	{
		cM = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[cM])
				cM = j;
		}
		if (cM != i)
		{
			tmp = array[cM];
			array[cM] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
