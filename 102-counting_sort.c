#include "sort.h"

/**
 * get_max - finds the maximum value in an array.
 * @array: the array to sort.
 * @size: size of array to sort.
 *
 * Return: max integer value.
*/
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm.
 * @array: the array to sort.
 * @size: size of array to sort.
 *
 */
void counting_sort(int *array, size_t size)
{
	int i, k, n = (int)size;
	int *count;
	int *temp;

	if (array == NULL || size < 2)
		return;

	k = get_max(array, size);

	count = malloc(sizeof(int) * (k + 1));
	temp = malloc(sizeof(int) * size);

	if (count == NULL || temp == NULL)
		return;

	for (i = 0; i < n; i++)
		count[i] = 0;

	for (i = 0; i < n; i++)
		count[array[i]]++;

	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	print_array(count, k + 1);

	for (i = n - 1;  i >= 0; i--)
		temp[--count[array[i]]] = array[i];

	for (i = 0; i < n; i++)
		array[i] = temp[i];

	free(temp);
	free(count);
}
