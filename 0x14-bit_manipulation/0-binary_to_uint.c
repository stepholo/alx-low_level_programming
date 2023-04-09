#include "main.h"

/**
 * binary_to_unint - Converts a binary number to unsigned int
 * @b: pointer to the string of 0 and 1
 *
 * Return: 0 if their is a string other than 0 or 1 or b is NULL
 * otherwise, the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int sum = 0;
	int i;


	if (b[i] == '\0')
	{
		return (0);
	}

	for(i = 0; (b[i] == '0') || (b[i] == '1'); i++)
	{
		sum <<= 1;
		sum += b[i] - '0';
	}

	return (sum)

			




