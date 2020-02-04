#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap, tmp, i, j;

	if (!array || size < 2)
		return;
	for (gap = 1; gap < (int)size / 3; gap = gap * 3 + 1)
		;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, (int)size);
	}
}
