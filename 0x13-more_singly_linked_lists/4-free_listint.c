#include "lists.h"

/**
 * free_listint - frees the list of memory allocation
 * @head: node to begin with
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *current = head;

	while (current != NULL)
	{
		listint_t *next = current->next;

		free(current);
		current = next;
	}
}
