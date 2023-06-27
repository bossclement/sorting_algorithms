#include "sort.h"

/**
 * bubble_sort - sorts numbers in ascending form.
 * @array: array of integers.
 * @size: the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, temp;

	for (i = 0; i < (int) size - 1; i++)
	{
		for (j = 0; j < (int) size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
