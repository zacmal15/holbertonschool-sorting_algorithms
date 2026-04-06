#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of integers in
 * ascending order using insertion sort
 * @list: pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	/*if list is NULL or has less than 2 elements, no sorting needed */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* start from second node */
	current = (*list)->next;

	/* traverse list */
	while (current != NULL)
	{
		key = current;

		/* move backwards while current node is smaller */
		while (key->prev != NULL && key->n < key->prev->n)
		{
			/* swap nodes */
			if (key->prev->prev != NULL)
				key->prev->prev->next = key;
			else
				*list = key;

			key->prev->next = key->next;
			if (key->next != NULL)
				key->next->prev = key->prev;

			key->next = key->prev;
			key->prev = key->next->prev;

			key->next->prev = key;

			/* print list after swap */
			print_list(*list);
		}

		/* move to next node */
		current = current->next;
	}
}
