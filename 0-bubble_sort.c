#include "sort.h"

/**
 * bubble_sort - sorts numbers in ascending form.
 * @array: array of integers.
 * @size: the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t cur, index = 0;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (; index < size; index++)
	{
		cur = index;
		while (cur < size && array[cur] > array[cur + 1])
		{
			temp = array[cur];
			array[cur] = array[cur + 1];
			array[cur + 1] = temp;
			cur++;
			print_array(array, size);
		}
		index = cur;
	}
	for (index = 0; index < size; index++)
	{
		if (array[index] > array[index + 1])
		{
			bubble_sort(array, size);
			break;
		}
	}
}
