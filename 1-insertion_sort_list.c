#include "sort.h"

/**
 * node_swap - Swap two nodes in a listint_t doubly-linked list.
 * @head: Pointer to the head of the doubly-linked list.
 * @first_node: Pointer to the first node to swap.
 * @second_node: The second node to swap.
 */
void node_swap(listint_t **head, listint_t **first_node,
				listint_t *second_node)
{
	(*first_node)->next = second_node->next;
	if (second_node->next != NULL)
		second_node->next->prev = *first_node;
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;

	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;
	else
		*head = second_node;

	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers.
 * @list: Pointer to the head of the list.
 * Description: prints the list after each swap.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *insert_node, *next_node;

	if (!list || !*list || !(*list)->next)
		return;

	for (current_node = (*list)->next; current_node; current_node = next_node)
	{
		next_node = current_node->next;
		insert_node = current_node->prev;

		while (insert_node && current_node->n < insert_node->n)
		{
			node_swap(list, &insert_node, current_node);
			print_list((const listint_t *)*list);
		}
	}
}
