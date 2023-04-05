#include "lists.h"

/**
 * sum_listint - adds all the data of all the nodes
 * @head: a pointer to the first node
 *
 * Return: 0 if the list is empty
 * Otherwise the summation of the data in the list
 */
int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		if (current == NULL)
		{
			return (0);
		}
		else
		{
			sum += current->n;
		}
		current = current->next;
	}

	return (sum);
}
