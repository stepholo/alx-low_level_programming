#include <unistd.h>

/**
 * main - prints to string
 * Description: Prints "and that piece of art is useful.." without puts/printf
 * Return: Always 1 (Success)
 */

int main(void)
{
	char str1[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(2, str1, 59);
	return (1);
}
