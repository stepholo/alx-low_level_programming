#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: a pointer to the bit
 * @index: The index to set the value at with indeces starting at 0
 *
 * Return: -1 for error otherwise 1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	mask = 1;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask <<= index;

	*n &= ~mask;
	return (1);
}
