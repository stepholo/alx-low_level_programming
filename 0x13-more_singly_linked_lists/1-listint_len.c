#include "lists.h"
#include <stdio.h>

/**
 * listint_len - counts the number of elements in a list
 * @h: the list
 *
 * Return: the number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
