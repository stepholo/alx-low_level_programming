#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list
 * @head: A pointer to the address of the head of the listint_t list
 *
 * Desc: Sets the head to NULL
 */
void free_listint2(listint_t **head)
{
	listint_t *tempr;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		tempr = *head;
		free(*head);
		*head = tempr->next;
	}
	head = NULL;
}
