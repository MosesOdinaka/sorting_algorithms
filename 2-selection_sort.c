#include "sort.h"

/**
 * swap_ints - Swaps the values of two integer variables.
 * @a: Pointer to the first integer variable.
 * @b: Pointer to the second integer variable.
*/

void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: Pointer to the first element of the array to be sorted.
 * @size: The number of elements in the array.
 *
 * Example:
 * int arr[] = {5, 4, 3, 2, 1};
 * selection_sort(arr, 5);
*/

void selection_sort(int *array, size_t size)
{
	int *min_value;
	size_t outer_index, inner_index;

	if (!array || size < 2)
		return;

	for (outer_index = 0; outer_index < size - 1; outer_index++)
	{
		min_value = array + outer_index;
		for (inner_index = outer_index + 1; inner_index < size; inner_index++)
			min_value = (array[inner_index] < *min_value) ? (array + inner_index)
					: min_value;

		if ((array + outer_index) != min_value)
		{
			swap_ints(array + outer_index, min_value);
			print_array(array, size);
		}
	}
}
