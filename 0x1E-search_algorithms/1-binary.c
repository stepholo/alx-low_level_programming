#include "search_algos.h"

/**
 * binary_search - function that searches for a value in a sorted
 * array of integers using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value is the value to search for
 * Return: The index where value is located
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t L, R, m, i;

	if (array == NULL)
		return (-1);

	L = 0;
	R = size - 1;

	while (L <= R)
	{
		printf("Searching in array: ");
		for (i = L; i <= R; i++)
		{
			printf("%d", array[i]);
			if (i < R)
				printf(", ");
		}
		printf("\n");

		m = L + (R - L) / 2;

		if (array[m] == value)
			return (m);
		else if (array[m] < value)
			L = m + 1;
		else
			R = m - 1;
	}
	return (-1);
}
