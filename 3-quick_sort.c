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
 * partition - process executing on a process.
 * @array: array to partition.
 * @size: size of array.
 * @lo: lower bound.
 * @hi: upper bound.
 *
 * Return: current end position.
*/
int partition(int *array, size_t size, int lo, int hi)
{
	int pivot, i, j;

	pivot = array[hi];

	i = lo - 1;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			arr_swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}

	i++;
	arr_swap(&array[i], &array[hi]);
	if (array[i] != array[j])
		print_array(array, size);
	return (i);
}


/**
 * qs - sorts an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: array to sort.
 * @size: size of array.
 * @lo: lower bound.
 * @hi: upper bound.
 *
 */
void qs(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(array, size, lo, hi);

	qs(array, size, lo, p - 1);
	qs(array, size, p + 1, hi);
}

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: array to sort.
 * @size: size of array to sort.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs(array, size, 0, size - 1);
}
