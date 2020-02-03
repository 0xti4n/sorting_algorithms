#include "sort.h"

/**
* partition - function that partition the array
* @array: the array
* @low: the firts position of the array
* @high: the position final.
* @size: the size of the array
* Return: the number of i.
*/

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot, tmp, num;
	int i = (int)low - 1;
	size_t j;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j < high; j++)
	{
		num = array[j];
		if (num < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != (int)j)
				print_array(array, size);
		}
	}
	i++;
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	if (i != (int)high)
		print_array(array, size);
	return (i);
}

/**
* quick - function that call partition
* @array: the array
* @low: the firts position of the array
* @high: the position final.
* @size: the size of the array
* Return: the number of i.
*/

void quick(int *array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		if (pi != 0)
		{
			quick(array, low, pi - 1, size);
		}
		quick(array, pi + 1, high, size);
	}
}

/**
* quick_sort - Entry point
* @array: the array.
* @size: the size of the array
* Return: nothing
*/

void quick_sort(int *array, size_t size)
{
	if (size > 1)
	{
		quick(array, 0, size - 1, size);
	}
}
