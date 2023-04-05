#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list
 * @head: A pointer to the address of the head of the listint_t list
 *
 * Desc: Sets the head to NULL
 */
void free_listint2(listint_t **head)
{
	if (head == NULL || *head == NULL)
	{
		return;
	}

	listint_t *current = *head;

	while (current != NULL)
	{
		listint_t *next = current->next;

		free(current);
		current = next;
	}

	*head = NULL;
}
