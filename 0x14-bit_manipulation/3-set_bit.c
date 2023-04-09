#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: a pointer to the bit
 * @index: The index to set the value at with indices starting at 0
 * Return: -1 for error
 * otherwise 1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int)) * 8)
		return (-1);

	*n ^= (1 << index);

	return (1);
}

