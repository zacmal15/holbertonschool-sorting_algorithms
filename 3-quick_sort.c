#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array of integers
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	/* If array is NULL or has less than 2 elements, do nothing */
	if (array == NULL || size < 2)
		return;

	/* Start the recursive quick sort on the full array */
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - recursively sorts part of an array
 * @array: array of integers
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: total size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	/* Only sort if the partition has more than one element */
	if (low < high)
	{
		/* Partition the array and get the pivot final position */
		pivot_index = lomuto_partition(array, low, high, size);

		/* Sort the left side of the pivot */
		quick_sort_recursive(array, low, pivot_index - 1, size);

		/* Sort the right side of the pivot */
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - partitions an array using Lomuto scheme
 * @array: array of integers
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: total size of the array
 *
 * Return: final index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	/* Pivot is always the last element */
	pivot = array[high];

	/* i marks the end of the smaller-elements section */
	i = low - 1;

	/* j scans the partition from left to right */
	for (j = low; j < high; j++)
	{
		/* If current element is smaller than pivot */
		if (array[j] < pivot)
		{
			i++;

			/* Swap only if the two positions are different */
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	/* Put pivot in its correct sorted position */
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
