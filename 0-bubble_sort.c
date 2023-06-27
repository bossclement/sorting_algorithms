#include "sort.h"

/**
 * bubble_sort - sorts numbers in ascending form.
 * @array: array of integers.
 * @size: the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t cur = 1, index = 0, p_cur = 0;
	int p_num;

	if (array == NULL || size < 2)
		return;

	for (; index < size; index++)
	{
		if (p_cur)
			cur = p_cur + 1;
		p_cur = cur;
		while (cur && cur < size && array[cur - 1] > array[cur])
		{
			p_num = array[cur - 1];
			array[cur - 1] = array[cur];
			array[cur] = p_num;
			cur--;
			print_array(array, size);
		}
	}
}
