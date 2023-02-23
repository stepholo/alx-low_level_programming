#include "main.h"

/**
 * print_most_numbers - Prints numbers from 0 to 9
 * except 2 and 4
 * Return: 0
 */
void print_most_numbers(void)
{
	int ch;

	for (ch = 0; ch <= 9; ch++)
	{
		if (ch != 2 && ch != 4)
		{
			_putchar(ch + '0');
		}
		_putchar('\n');
	}
}

