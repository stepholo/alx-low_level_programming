#include "main.h"

/**
 * more_numbers - Prints number from 0 to 14
 * Return: 0
 */

void more_numbers(void)
{
	int ch, sh;

	for (ch = 0; ch <= 9; ch++)
	{
		for (sh = 0; sh <= 14; sh++)
		{
			if (sh >= 10)
				_putchar((sh / 10) + 48);
			_putchar((sh % 10) + 48);

		}
		_putchar('\n');
	}
}
