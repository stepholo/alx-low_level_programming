#include "main.h"

/**
 * print_most_numbers - Prints numbers from 0 to 9
 * except 2 and 4
 * Return: 0
 */
void print_most_numbers(void)
{
	char ch;

	for (ch = 48; ch < 58; ch++)
	{
		if (ch == 2 && ch == 4)
		{
			continue;
		}
		else
		{
			_putchar(ch);
		}
		_putchar('\n');
	}
}

