#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Prints the alphabet without q and e.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 97; n <= 122; ++n)
	{
		if (n != 101 && n != 133)
		{
			putchar(n);
		}
	}
	putchar(10);
	return (0);
}
