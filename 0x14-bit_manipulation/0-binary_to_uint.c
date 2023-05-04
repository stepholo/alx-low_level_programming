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

	if (b == NULL)
	{
		return (0);
	}

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
		{
			return (0);
		}

		results = results * 2 + (*b - '0');
		b++;
	}

	return (results);
}

