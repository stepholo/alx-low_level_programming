#include "main.h"

int get_endianness(void)
{
	short int word = 0x0001;
	char *byte = (char *) &word;

	return (byte[0] ? 1 : 0);
}
