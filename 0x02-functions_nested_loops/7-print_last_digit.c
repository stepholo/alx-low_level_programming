#include  "main.h"

/**
 * print_last_digit - Entry point
 * @n: the integer it receives
 * Description: Prints the last digit of a number
 * Return: int
 */

int print_last_digit(int n)
{
	int c = n % 10;

	if (n < 0)
	{
		c *= -1;
	}
	_putchar(c + '0');
	return (c);
}

