#include "lists.h"

/**
 * get_nodeint_at_index - locats a given node of a listint_t linked list
 * @head: A pointer tothe head of he listint_t list.
 * @index: The index of the node to locate - indices starts at 0.
 *
 * Return: If the node does not exist - NULL
 * Otherwise - the located node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int list_t = 0;

	while (list_t < index)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
		list_t++;
	}

	return (head);
}

