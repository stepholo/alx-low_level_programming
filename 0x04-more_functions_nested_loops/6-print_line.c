#include "main.h"

/**
 * print_line - draws a straight line on the terminal
 * @n: times straight line is printed
 * Return: not retuen.
 */

void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar(95);
	}
	_putchar('\n');
}
