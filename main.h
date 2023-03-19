#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_alphabet - Prints the alphabet in lowercase followed by a new line
 * Return: void
 */

void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}

/**
 * print_alphabet_x10 - prints 10 times the alphabets in lowercase
 * followed by new line
 * Return: void
 */

void print_alphabet_x10(void)
{
	char c;
	int i;

	for (i = 0; i <= 9; i++)
	{
		for (c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);
		}
		_putchar('\n');
	}
}

/**
 * _islower - checks for a lowercase character
 * @c: Character to be checked
 *
 * Return: 1 if character is lowercase, 0 if otherwise.
 */

int _islower(int c)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (c == i)
		{
			return (1);
		}

	}
	return (0);
}

/**
 * _isalpha - checks for alphabetic character;
 * @c: character to be checked
 *
 * Return: 1 if c is a letter, lowercase or uppercase
 * 0 otherwise
 */

int _isalpha(int c)
{
	int i;

	for (i = 'A'; i <= 'z'; i++)
	{
		if (c == i)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * print_sign - prints sign of a number
 * @n: number to be checked
 *
 * Return: 1 and prints + if n is greater than zero
 * 0 and prints 0 if n is zero
 * -1 and prints - if n is less than zero
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}

/**
 * _abs - computes the absolute value of an integer
 * @int: number to be checked is an integer
 * Return: number
 */

int _abs(int i)
{
	if (i == 0)
	{
		return (0);
	}
	else if (i > 0)
	{
		return (i);
	}
	else
		return (-i);
}

#endif
