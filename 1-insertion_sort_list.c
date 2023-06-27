#include "sort.h"

void swap_nodes(listint_t *left, listint_t *right, listint_t **list);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_nodes(temp->prev, temp, list);
			print_list(*list);
		}
	}
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @left: Pointer to the left node to swap.
 * @right: Pointer to the right node to swap.
 * @list: Double pointer to the head of the list.
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	listint_t *prev, *next;

	prev = left->prev;
	next = right->next;

	if (prev != NULL)
		prev->next = right;
	else
		*list = right;

	if (next != NULL)
		next->prev = left;

	left->next = next;
	left->prev = right;
	right->next = left;
	right->prev = prev;
}

