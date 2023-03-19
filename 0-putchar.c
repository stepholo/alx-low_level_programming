#include "main.h"

int _putchar(char c);

/**
 * _putchar - A program that prints "_putchar"
 * @c: Character to be printed
 * Return: void
 */

int main(void)
{
	char c, str[] = "_putchar\n";
	int i;

	while (str[i] != '\0')
	{
		c = str[i];
		_putchar(c);
		i++;
	}
	return (0);
}
