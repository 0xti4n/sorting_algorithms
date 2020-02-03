#include "sort.h"

/**
* main - Entry point
*
* Return: Always 0
*/

unsigned int partition(int *array, unsigned int low, unsigned int high)
{
	int pivot, tmp, num;
	unsigned int i, j;

	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		num = array[j];
		if (num <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	i++;
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	return (i);

}

/**
* main - Entry point
*
* Return: Always 0
*/
void quick(int *array, size_t low, size_t high)
{
	unsigned int pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quick(array, low, pi);
		quick(array, pi + 1, high);
	}
}

/**
* main - Entry point
*
* Return: Always 0
*/

void quick_sort(int *array, size_t size)
{
	quick(array, 0, size - 1);
}