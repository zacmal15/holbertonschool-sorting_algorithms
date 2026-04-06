#include "sort.h"

/**
 * selection_sort - sorts array of integers in
 * ascending order using selection sort algorithm
 * @array: array of integers
 * @size: number of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	/* if array is NULL or size < 2, dont sort */
	if (array == NULL || size < 2)
		return;

	/* loop through array */
	for (i = 0; i < size - 1; i++)
	{
		/* assume current index is minimum */
		min_index = i;

		/* find smallest element in remaining array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		/* swap only if smaller element was found */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			/* print array after swap */
			print_array(array, size);
		}
	}
}
