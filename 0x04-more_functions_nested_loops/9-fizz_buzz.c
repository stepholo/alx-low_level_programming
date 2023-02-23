#include <stdio.h>

/**
 * main -prints 1 to 100
 * for multiple of 3 prints Fizz
 * for multiple of 5 prints Buzz
 * for multiple of 3 and 5 prints FizzBuzz
 * Return: no return
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz");
		}
		else
		{
			printf("%i", i);
		}
		if (i != 100)
		{
			putchar(' ');
		}

	}
	putchar('\n');
	return (0);
}

