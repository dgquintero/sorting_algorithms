#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, item;

	for (i = 0; i < size - 1; i++)
	{
		item = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[item])
				item = j;
		}
		if (item != i)
		{
			item_swap(&array[item], &array[i]);
			print_array(array, size);
		}
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
