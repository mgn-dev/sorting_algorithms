#include "sort.h"
#include <stdio.h>

/**
 * _ceil - rounds a floating point number up to nearest
 * interger.
 * @num: number to round up.
 *
 * Return: a rounded up double.
*/
double _ceil(double num)
{
	int i = (int)num;
	double res = 0, dec = 0;

	dec = num / i;

	if (dec == 1.0)
		res = num;
	else
		res = (num / dec) + 1;

	return (res);
}

/**
 * _pow - raises a number to the power of another number.
 * @x: a base number.
 * @y: a power number.
 *
 * Return: a double.
*/
double _pow(int x, int y)
{
	int i;
	double result = 1;

	for (i = y; i > 0; i--)
		result *= x;

	return (result);
}


/**
 * calc_max_term - calculates the highest term for a fitting gap.
 * @size: size of array to calculate gap for.
 *
 * Return: returns an int representing the kth term.
*/
int calc_max_term(size_t size)
{
	double upper_limit = _ceil(size / 3);
	int curr_gap = 1, k = 1;

	(void)k;
	(void)curr_gap;
	(void)upper_limit;

	for (k = 1; curr_gap <= upper_limit; k++)
		curr_gap = (int)((_pow(3, k) - 1) / 2);

	if (k <= 1)
		k = 1;
	else
		k--;

	return (k);
}

/**
 * calc_gap - calculates the fitting gap for an array of integers
 * using the Knuth sequence.
 * @k: size of array to calculate gap for.
 *
 * Return: returns a fitting gap.
*/
int calc_gap(int k)
{
	int gap = (int)((_pow(3, k) - 1) / 2);

	return (gap);
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: array to sort.
 * @size: size of array to sort.
 *
 */
void shell_sort(int *array, size_t size)
{
	int temp, k, i, j, gap, n = (int)size;

	if (array == NULL || size < 2)
		return;

	for (k = calc_max_term(size); k >= 1; k--)
	{
		gap = calc_gap(k);

		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j + gap] > array[j])
					break;

				temp = array[j + gap];
				array[j + gap] = array[j];
				array[j] = temp;
			}
		}

		print_array(array, size);
	}
}
