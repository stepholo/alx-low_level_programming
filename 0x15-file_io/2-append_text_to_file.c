#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: A pointer to the name of the file
 * @text_content: The string to add to the end of the file
 *
 * Return: If the function fails or filename is NULL -1
 * If the file does not exist the user lacks write permissions -1
 * otherwise 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int _open, _write, bytes = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (bytes = 0; text_content[bytes];)
			bytes++;
	}

	_open = open(filename, O_WRONLY | O_APPEND);
	_write = write(_open, text_content, bytes);

	if (_open == -1 || _write == -1)
		return (-1);

	close(_open);
	return (1);
}
