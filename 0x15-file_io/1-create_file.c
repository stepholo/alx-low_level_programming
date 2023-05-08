#include "main.h"

/**
 * create_file - Creates a file
 * @filename: A pointer to the name of the file to create
 * @text_content: A pointer to a string to write to the file
 *
 * Return: If the function fails -1
 * otherwise 1
 */
int create_file(const char *filename, char *text_content)
{
	int _open, _write, bytes = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (bytes = 0; text_content[bytes];)
			bytes++;
	}

	_open = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	_write = write(_open, text_content, bytes);
	if (_open == -1 || _write == -1)
		return (-1);

	close(_write);
	return (1);
}
