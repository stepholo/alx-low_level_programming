#include "fuction_pointers.h"

/**
 * array_iterator - executes a funtion given as ae
 * parameter on each element of an array
 * @array: input integer array
 * @size: size the arraye
 * @action: pointer to the function
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array && action)
		for (i = 0; i < size; i++)
			action(array[i]);
}
