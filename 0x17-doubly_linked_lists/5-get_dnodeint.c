#include "lists.h"

/**
* get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
* @head: Pointer to the head of the list.
* @index: Index of the node, starting from 0
*
* Return: The nth node of the list, or NULL if it doesn't exist
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}

	return (NULL);
}
