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

	if (list == NULL || *list == NULL || (*list)->next == NULL)
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
 * swap - swaps a two nodes in a doubly linked list
 *
 * @node: given node
 * @list: pointer to pointer to doubly linked list
 *
 * Return: pointer to swaped node
*/
listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev, *next_node = node->next;

	/* if prev is not null */
	if (prev_node)
		prev_node->next = next_node;

	/* if next is not null */
	if (next_node)
		next_node->prev = prev_node;

	node->prev = prev_node->prev;
	node->next = prev_node;

	if (node->prev)
		node->prev->next = node;
	else
		*list = node;

	prev_node->prev = node;

	return (node);
}
