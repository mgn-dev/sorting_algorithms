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
 * bubble_sort -  sorts an array of integers in ascending
 * order using the Bubble sort algorithm.
 * @array: array to sort.
 * @size: size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				arr_swap(&array[j], &array[j + 1]);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
