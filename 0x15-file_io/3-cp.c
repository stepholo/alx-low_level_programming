#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error - Prints the error message
 * @message: Pointer to the message to be printed in STDERR
 * @code: The exit code
 */
void error(const char *message, int code)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(code);
}

/**
 * copy_file - copy the content of one file to another
 * @file_from: Pointer to the file to copy from
 * @file_to: Pointer to the file to copy to
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error(file_from, 98);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		error(file_to, 99);

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			error(file_to, 99);
	}

	if (bytes_read == -1)
		error(file_from, 98);

	if (close(fd_from) == -1)
		error("Can't close fd", 100);

	if (close(fd_to) == -1)
		error("Can't close fd", 100);
}

/**
 * main - Program to copy from one file to another
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

