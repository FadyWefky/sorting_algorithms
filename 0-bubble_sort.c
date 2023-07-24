#include "sort.h"
/**
 * bubble_sort - function that sorts an array using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	int isSwapped = 0;
	size_t i;
	size_t j;
	/* Iterate through the array */
	for (i = 0; i < size; i++)
	{
		/* Compare adjacent elements and swap if necessary */
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				/* Set flag to indicate a swap occurred */
				isSwapped = 1;
				print_array(array, size); /* Print the array after each swap */
			}
		}
		/* If no swap occurred in the inner loop, the array is already sorted */
		if (isSwapped == 0)
		{
			break;
		}
	}
}
