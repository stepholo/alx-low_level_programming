#include "main.h"

#define BUFFER_SIZE 1024

/**
 * handle_error - Handle the error messages in copy_file function
 * @file_from: Pointer to the file name being read
 * @file_to: Pointer to the file name being written
 * @error_code: The error code
 */
void handle_error(const char *file_from, const char *file_to, int error_code)
{
	switch (error_code)
	{
		case 2:
			dprintf(STDERR_FILENO, "Error: Can't open fd\n");
			break;
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from %s\n", file_from);
			break;
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			break;
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close fd\n");
			break;
		default:
			dprintf(STDERR_FILENO, "Unknown error occured\n");
			break;
	}
	exit(error_code);
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
		handle_error(file_from, file_to, 2);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		handle_error(file_from, file_to, 2);

	bytes_read = read(fd_from, buffer, BUFFER_SIZE);

	do {
		if (fd_from == -1 || bytes_read == -1)
			handle_error(file_from, file_to, 98);

		bytes_written = write(fd_to, buffer, bytes_read);
		if (fd_to == -1 || bytes_written == -1)
			handle_error(file_from, file_to, 99);

		bytes_read = read(fd_from, buffer, BUFFER_SIZE);
		fd_to = open(file_to, O_WRONLY | O_APPEND);

	} while (bytes_read > 0);

	if (bytes_read == -1)
		handle_error(file_from, file_to, 98);

	if (close(fd_from) == -1 || close(fd_to) == -1)
		handle_error(file_from, file_to, 100);
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
	argv[0] = "cp";

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}

