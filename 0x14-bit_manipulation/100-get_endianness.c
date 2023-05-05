#include "main.h"

/**
 * get_endianness - Checks the endianness
 * Return: void
 */
int get_endianness(void)
{
	short int word = 0x0001;
	char *byte = (char *) &word;

	return (byte[0] ? 1 : 0);
}
