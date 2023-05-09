#include "main.h"

/**
 * _check_elf - Checks if a file is an ELF file
 * @e_ident: A pointer to an array containing the ELF magic numbers
 * Description: If the file is not an ELF file - exit code 98
 */
void _check_elf(unsigned char *e_ident)
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
 * _close_elf - Closes an ELF file
 * @_elf: The file descriptor of the ELF file
 * Description: If the file cannot be closed - exit code 98
 */
void _close_elf(int _elf)
{
	if (close((_elf) == -1))
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", _elf);
		exit(98);
	}
}

/**
 * printf_entry - Prints the entry point of an ELF headers
 * @e_entry: The address of the ELF entry point
 * @e_ident: A pointer to an array containing the ELF class
 */
void printf_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:		 ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0XFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%lx\n", e_entry);
}

/**
 * printf_type - Prints the type of an ELF header.
 * @e_type: The ELF type
 * @e_ident: A pointer to an array containing the ELF class
 */
void printf_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type				");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * printf_abi - Prints the ABI Version of an ELF header.
 * @e_ident: A pointer toa n array containing the ELF ABI Version
 */
void printf_abi(unsigned char *e_ident)
{
	printf("  ABI Version:			%d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * printf_osabi - Prints the OS / ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version
 */
void printf_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI			");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printf_version - Prints the version of an ELF header
 * @e_ident: A pointer to an array containing the ELF version
 */
void printf_version(unsigned char *e_ident)
{
	printf("  Version:			%d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * printf_data - Prints the data of an ELF header.
 * @e_ident: A pointer toa n array containing the ELF class.
 */
void printf_data(unsigned char *e_ident)
{
	printf("  Data:				");

	switch (e_ident[EI_DATA])
	{
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	case ELFDATANONE:
		printf("none\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printf_class - Prints the class of an ELF header
 * @e_ident: A pointer to an array containig the EFL class
 */
void printf_class(unsigned char *e_ident)
{
	printf("  Class:			");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("EFL64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printf_magic - Prints the magic number of an EFL header.
 * @e_ident: A pointer toa n array containing the ELF magic number.
 * Description: Magic numbers are seperated by spaces
 */
void printf_magic(unsigned char *e_ident)
{
	int no;

	printf("  Magic:   ");

	for (no = 0; no < EI_NIDENT; no++)
	{
		printf("%02x", e_ident[no]);

		if (no == EI_NIDENT - 1)
			printf("\n");

		else
			printf(" ");
	}
}

/**
 * main - Displays the information contained in the ELF header at the start
 * of the ELF file
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on success
 *
 * Description: If the file is not an ELF  file of the 
 * function fails - exit code 98.
 */
int main(int argc, char **argv)
{
	Elf64_Ehdr *header;
	int _o, _r;
	(void)argc;

	_o = open(argv[1], O_RDONLY);
	if (_o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		_close_elf(_o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	_r = read(_o, header, sizeof(Elf64_Ehdr));
	if (_r == -1)
	{
		free(header);
		_close_elf(_o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	_check_elf(header->e_ident);
	printf("ELF Header:\n");
	printf_magic(header->e_ident);
	printf_class(header->e_ident);
	printf_data(header->e_ident);
	printf_version(header->e_ident);
	printf_osabi(header->e_ident);
	printf_abi(header->e_ident);
	printf_type(header->e_type, header->e_ident);
	printf_entry(header->e_entry, header->e_ident);
	free(header);
	_close_elf(_o);
	return (0);
}
			
