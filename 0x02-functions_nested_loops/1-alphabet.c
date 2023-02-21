#include "main.h"

/**
 * print_alphabet - Entry point
 * Description: a function that prints alphabets
 * in lower case followed by a new line
 * Return: void
 */
void print_alphabet(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		_putchar(letter);
		letter++;
	}
	_putchar('\n');
}
