#include "sort.h"

/* function declaretion*/
listint_t *swap(listint_t *node, listint_t **list);

/**
 * insertion_sort_list - sorts a doubly linked list of integer in asc
 *			order
 * @list: pointer to poiner of a doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;

	if (list == NULL || (*list) == NULL)
		return;

	while (curr)
	{
		while ((curr->prev) && (curr->n < curr->prev->n))
		{
			curr = swap(curr, list);
			print_list(*list);
		}
		curr = curr->next;
	}
}

/**
 * swap - swaps a node with its previous
 *
 * @node: given node
 * @list: pointer to pointer to doubly linked list
 *
 * Return: pointer to swaped node
*/
listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev, *curr = node;

	prev->next = curr->next;

	if (curr->next)
		curr->next->prev = prev;

	curr->next = prev;
	curr->prev = prev->prev;
	prev->prev = curr;

	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;

	return (curr);
}
