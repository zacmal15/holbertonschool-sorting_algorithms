#include "sort.h"

/**
 * bubble_sort - sorts array of ints in ascending order
 * using the bubble sort algorithm
 * @array: array of integers
 * @size: number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	/* if array is NULL , or size < 2, dont sort */
	if (array == NULL || size < 2)
		return;

	/* outer loop: controls number of passes */
	for (i = 0; i < size - 1; i++)
	{
		/* inner loop: compares adjacent elements */
		for (j = 0; j < size - 1 - i; j++)
		{
			/* if current element is greater than next, swap */
			if (array[j] > array[j + 1])
			{
				/* swap values */
				temp = array[j];
				array[j] = array[j +  1];
				array[j + 1] = temp;

				/* print array for each swap */
				print_array(array, size);
			}
		}
	}
}
