#include "main.h"
#include <elf.h>
#include <errno.h>
#include <stdint.h>

/**
 * error_exit - Exit error message
 * @message: Error message
 */
void error_exit(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * display_elf_header - Displays elf header
 * @header: Elf header
 */
void display_elf_header(const Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("Magic: %.4s\n", header->e_ident);
	printf("Class: %d-bit\n", header->e_ident[4] == 1 ? 32 : 64);
	printf("Data: %s\n", header->e_ident[5] == 1 ?
			"little endian" : "big endian");
	printf("Version: %d\n", header->e_ident[6]);
	printf("OS/ABI: %d\n", header->e_ident[7]);
	printf("ABI Version: %d\n", header->e_ident[8]);
	printf("Type: %u\n", header->e_type);
	printf("Entry point address: Ox%1lx\n", header->e_entry);
}

/**
 * check_elf - Checks if a file is an ELF file
 * @e_ident: A pointer to an array containing the ELF magic numbers
 *
 * Description: If the file is not an ELF file - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int no = 0;

	while (no < 4)
	{
		if (e_ident[no] != 127 &&
		    e_ident[no] != 'E' &&
		    e_ident[no] != 'L' &&
		    e_ident[no] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		no++;
	}
}

/**
 * read_elf_header - reads elf header
 * @filename: Pointer to the file having elf info
 */
void read_elf_header(const char *filename)
{
	Elf64_Ehdr *header;
	ssize_t bytes_read;
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		error_exit("Error opening file.");

	bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr))
		error_exit("Error reading file.");

	check_elf(header->e_ident);

	display_elf_header(header);

	close(fd);
}

/**
 * main - Program to read elf file
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	read_elf_header(argv[1]);

	return (0);
}
