#include "main.h"

/**
 * flip_bits - counts the number of bits you would need to flip
 * to get from one number to another
 * @n: the number
 * @m: the number to flip n to
 *
 * Return: The necessary no of bits to flip to get from n to m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int i = n ^ m, j = 0;

	while (i > 0)
	{
		j += (i & 1);
		i >>= 1;
	}

	return (j);
}
