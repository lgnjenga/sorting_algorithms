#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *temp_prev = node1->prev;
	listint_t *temp_next = node2->next;

	if (temp_prev != NULL)
		temp_prev->next = node2;
	else
		*head = node2;

	if (temp_next != NULL)
		temp_next->prev = node1;

	node1->prev = node2;
	node1->next = temp_next;
	node2->prev = temp_prev;
	node2->next = node1;

	if (temp_next != NULL)
		temp_next->prev = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list
 * using insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current;
	current = (*list)->next;

	while (current != NULL)
	{
		listint_t *inner = current->prev;
		int key = current->n;

		while (inner != NULL && inner->n > key)
		{
			swap_nodes(list, inner, current);
			inner = current->prev;
		}

		current = current->next;
	}
}
