#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of the listint_t list
 * @head: a pointer to the address of the head of the listint_t list.
 * @n: The data for the new node
 *
 * Return: address of the elements and NULL if function fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *fresh;
	listint_t *end;

	fresh = malloc(sizeof(listint_t));
	if (fresh == NULL)
		return (NULL);
	fresh->n = n;
	fresh->next = NULL;
	if (*head == NULL)
	{
		*head = fresh;
		return (fresh);
	}

	else
	{
		end = *head;
		while (end->next != NULL)
		{
			end = end->next;
		}
		end->next = fresh;

		return (fresh);
	}
}
