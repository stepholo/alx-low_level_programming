#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void _close(int file_desc);
char *create_buffer(char *doc);

/**
 * _close - Closes file descriptor
 * @file_desc: The file descriptor to be closed
 */
void _close(int file_desc)
{
	int i;

	i = close(file_desc);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file desc %d\n", file_desc);
		exit(100);
	}
}

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @doc: The name of the file buffer is storing char for
 *
 * Return: A pointer to the newly allocated buffer
 */
char *create_buffer(char *doc)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", doc);
		exit(99);
	}

	return (buffer);
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the programe
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the arguments count is incorrext - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98
 * If file_to cannot be created or written to - exit code 99
 * If file_to or file_from cannot be closed - exit code 100.
 *
 */
int main(int argc, char *argv[])
{
	int to, from, i, j;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	i = read(from, buffer, 1024);
	to = open(arg[2], O_CREATE | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", arg[2]);
			free(buffer);
			exit(99);
		}

		i = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (i > 0);

	free(buffer);
	_close(from);
	_close(to);

	return (0);
}

