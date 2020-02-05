#include "sort.h"
/**
 * quick_sort- function that sorts an array of integers
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickS(array, 0, size - 1, size);
}
/**
 * quickS - func that swap two elements
 *
 * @array: The array of integers to be sorted
 * @low: the low valeu
 * @high: the high valeu
 * @size: The size of the array
 */
void quickS(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, low, high);
		quickS(array, low, pivot - 1, size);
		quickS(array, pivot + 1, high, size);
	}
}
/**
 * item_swap - func that swap two elements
 *
 * @a: item a
 * @b: item b
 */
void item_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - a funtion to partitionate the array
 *
 * @array: The array of integers to be sorted
 * @size: the size of the array
 * @n_min: the min value
 * @n_max: the max value
 *
 * Return: an integer
 */
int partition(int *array, size_t size, int n_min, int n_max)
{
	int p = array[n_max];
	int i = n_min - 1, j;

	for (j = n_min; j < n_max; j++)
	{
		if (array[j] <= p)
		{
			i++;
			if (i != j)
			{
				item_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != n_max)
	{
		item_swap(&array[i + 1], &array[n_max]);
		print_array(array, size);
	}
	return (i + 1);
}
