#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: Values to convert to binary
 * @index: index to the bit to find
 *
 * Return: if error -1
 * otherwise value of the index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	if ((n & (1 << index)) == 0)
		return (0);

	return (1);
}
