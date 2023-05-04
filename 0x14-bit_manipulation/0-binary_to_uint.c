#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * and b is null
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int results = 0;
	int j = 0;

	if (b[j] == NULL)
	{
		return (0);
	}

	while ((b[j] == '0') || (b[j] == '1'))
	{
		results <<= 1;
		results += b[j] - '0';
		j++;
	}

	return (results);
}

