#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: Pointer to the first element of the array.
 * @size: Size of the array.
 *
 * Description: Implements bubble sort algorithm and
 * prints the array after each swap.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped = true;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1 && swapped; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				swapped = true;
			}
		}
	}
}
