#include "main.h"

/**
 * puts_half - Prints thd second half of ths string
 * @str: the string refference
 *
 * Return: no return
 */

void puts_half(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	i++;
	for (i /= 2; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
