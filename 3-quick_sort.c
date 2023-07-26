#include "sort.h"

void swap_elements(int *first, int *second);
int partition_array(int *array, size_t size, int start, int end);
void sort_partition(int *array, size_t size, int start, int end);
void quicksort(int *array, size_t size);

/**
 * swap_elements - Swap two elements in an array.
 * @first: Pointer to the first element to swap.
 * @second: Pointer to the second element to swap.
 */
void swap_elements(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * partition_array - Partition a subset of an array using the Lomuto scheme.
 * @array: Pointer to the array to partition.
 * @size: Size of the array.
 * @start: Starting index of the subset to partition.
 * @end: Ending index of the subset to partition.
 *
 * Return: The final partition index.
 */
int partition_array(int *array, size_t size, int start, int end)
{
	int pivot = array[end];
	int i = start;

	for (int j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_elements(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > pivot)
	{
		swap_elements(&array[i], &array[end]);
		print_array(array, size);
	}

	return (i);
}

/**
 * sort_partition - Recursively sort a partition of an array using Quick sort.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 * @start: Starting index of the partition to sort.
 * @end: Ending index of the partition to sort.
 */
void sort_partition(int *array, size_t size, int start, int end)
{
	if (start < end)
	{
		int pivot_index = partition_array(array, size, start, end);

		sort_partition(array, size, start, pivot_index - 1);
		sort_partition(array, size, pivot_index + 1, end);
	}
}

/**
 * quicksort - Sort an array of integers in ascending order using Quick sort.
 * @array: Pointer to the array to sort.
 * @size: Size of the array.
 */
void quicksort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_partition(array, size, 0, size - 1);
}
