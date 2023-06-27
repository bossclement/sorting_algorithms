#include "sort.h"

void swap_nodes(listint_t **list, listint_t **n1, listint_t **n2);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *	in ascending order using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		/* Forward pass */
		for (start = *list; start->next != NULL; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, &start, &start->next);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		/* Backward pass */
		for (; start->prev != NULL; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, &start->prev, &start);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head of the doubly linked list.
 * @n1: Pointer to the first node.
 * @n2: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t **n1, listint_t **n2)
{
	listint_t *prev1 = (*n1)->prev;
	listint_t *next1 = (*n1)->next;
	listint_t *prev2 = (*n2)->prev;
	listint_t *next2 = (*n2)->next;

	if (prev1)
		prev1->next = *n2;
	if (next2)
		next2->prev = *n1;
	if (prev2)
		prev2->next = *n1;
	if (next1)
		next1->prev = *n2;

	(*n1)->prev = prev2;
	(*n1)->next = next2;
	(*n2)->prev = prev1;
	(*n2)->next = next1;

	if (!prev1)
		*list = *n2;
	if (!prev2)
		*list = *n1;
}

