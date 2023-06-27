#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *	in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted = *list, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (unsorted != NULL)
	{
		current = unsorted;
		unsorted = unsorted->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;

			print_list(*list);
		}
	}
}

