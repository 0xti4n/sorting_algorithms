#include "sort.h"

/**
* shell_sort - function that sorted an array.
* @array: array to sorted.
* @size: the size of the array.
* Return: Nothing.
*/

void shell_sort(int *array, size_t size)
{
	size_t num, in, out;
	int tmp;

	num = 1;
	while (num <= size / 3)
		num = num * 3 + 1;

	while (num > 0)
	{
		for (out = num; out < size; out++)
		{
			tmp = array[out];
			in = out;
			while (in > num - 1 && (array[in - num] >= tmp))
			{
				array[in] = array[in - num];
				in -= num;
			}
			array[in] = tmp;
		}
		num = (num - 1) / 3;
		print_array(array, size);
	}
}
