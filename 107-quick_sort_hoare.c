#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - swap two digits array
 * @a: first digit to swap
 * @b: second digit to swap
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - order subset array digits
 * according to hoare partition scheme
 * @array: array digits
 * @size: array size
 * @left: starting index of subset to order
 * @right: ending index of subset to order
 *
 * Return: final partition index
 *
 * Description: use last element partition as driver
 * print array after each swap of two elements
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int driver, up, down;

	driver = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < driver);
		do {
			down--;
		} while (array[down] > driver);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - implement quicksort algo through recursion
 * @array: array digits to sort
 * @size: array size
 * @left: starting index of array partition to order
 * @right: ending index of array partition to order
 *
 * Description: use hoare partition scheme
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, belong - 1);
		hoare_sort(array, size, belong, right);
	}
}

/**
 * quick_sort_hoare - sort array digits in ascending
 * order using quicksort algo
 * @array: array digits
 * @size: array size
 *
 * Description: use hoare partition scheme
 * print array after each swap of two elements
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
