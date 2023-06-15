#include "lists.h"

/**
* print_dlistint - Prints all elements of a distint_t list.
* @h: Pointer to the head of the list
* Return: the number of elements .
*/
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
