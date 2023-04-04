#include "lists.h"

/**
 * add_nodeint - adds node at the beginning of a list
 * @head: douple pointer to the new node
 * @n: data to be assigned to the new node
 *
 * Return: The address of the new element or null is failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *fresh_node;

	fresh_node = malloc(sizeof(listint_t));
	if (fresh_node == NULL)
	{
		return (NULL);
	}

	fresh_node->n = n;
	fresh_node->next = *head;

	*head = fresh_node;

	return (fresh_node);
}
