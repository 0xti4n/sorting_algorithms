#include "sort.h"

/**
* swap_array - sorts an array of integers in ascending order.
*
* @pa: position to swap
* @pb: position to swap
* Return: Nothing
*/

void swap_array(int *pa, int *pb)
{
	int tmp = 0;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

/**
* bubble_sort - sorts an array of integers in ascending order
*
* @array: array to sorted
* @size: the size of the array
* Return: Nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size != 2)
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap_array(&array[j], &array[j + 1]);
					print_array(array, size);
				}
			}
		}
	}
}
