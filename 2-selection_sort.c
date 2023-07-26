#include "sort.h"

/**
 * arr_swap - swaps a and b.
 * @a: first value to swap.
 * @b: second value to swap.
 *
*/
void arr_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 * @array: array to sort.
 * @size: size of array to sort.
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			arr_swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
