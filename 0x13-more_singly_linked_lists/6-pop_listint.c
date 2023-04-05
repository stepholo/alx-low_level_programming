#include "lists.h"

/**
 * pop_listint - Delets the head node of a listint_t liste
 * @head: a pointer to the address of the head of the listint_t list
 *
 * Return: is the list if empty - 0e
 * otherwise the head node's data (n)
 */
int pop_listint(listint_t **head)
{
	listint_t *delete;
	int data;

	if (*head == NULL)
		return (0);

	delete = *head;
	data = (*head)->n;
	*head = (*head)->next;

	free(delete);

	return (data);
}
