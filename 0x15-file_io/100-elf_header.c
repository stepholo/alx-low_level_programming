#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ELF_MAGIC "\x7F\x45\x4C\x46"

void display_elf_header(FILE *fp);
void print_hex_dump(const unsigned char *data, size_t size);
const char *get_type_name(unsigned int type);
const char *get_os_abi_name(unsigned char os_abi);

/**
 * main - Print the content of Elf header
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char magic[4];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		perror("fopen");
		exit(1);
	}

	if (fread(magic, 1, 4, fp) != 4)
	{
		perror("fread");
		exit(1);
	}

	if (memcmp(magic, ELF_MAGIC, 4) != 0)
	{
		fprintf(stderr, "Not an ELF file\n");
		exit(98);
	}

	rewind(fp);

	display_elf_header(fp);

	fclose(fp);
	return (0);
}

/**
 * print_hex_dump - Prints the magic file content
 * @data: Pointer to the string to be printed
 * @size: Size of the magic file
 * Return: no return
 */
void print_hex_dump(const unsigned char *data, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
	{
		printf("%02X ", data[i]);
		if ((i + 1) % 16 == 0)
			printf("\n");
	}
}

/**
 * get_type_name - Get the type of file
 * @type: value of the file
 * Return: type of file otherwise unknown
 */
const char *get_type_name(unsigned int type)
{
	switch (type)
	{
	case ET_NONE: return ("NONE (No file type)");
	case ET_REL: return ("REL (Relocatable file)");
	case ET_EXEC: return ("EXEC (Executable file)");
	case ET_DYN: return ("DYN (Shared object file)");
	case ET_CORE: return ("CORE (Core file)");
	default: return ("Unknown");
	}
}


/**
 * get_os_abi_name - Gets the name of the Operation system
 * @os_abi: OS/ABI contained in the header file
 * Return: name otherwise unknown
 */
const char *get_os_abi_name(unsigned char os_abi)
{
	switch (os_abi)
	{
	case ELFOSABI_SYSV: return ("UNIX - System V");
	case ELFOSABI_HPUX: return ("HP - UX");
	case ELFOSABI_NETBSD: return ("NetBSD");
	case ELFOSABI_LINUX: return ("Linux");
	case ELFOSABI_SOLARIS: return ("Solaris");
	case ELFOSABI_IRIX: return ("IRIX");
	case ELFOSABI_FREEBSD: return ("FreeBSD");
	case ELFOSABI_TRU64: return ("Tru64");
	case ELFOSABI_ARM: return ("ARM architecture");
	case ELFOSABI_STANDALONE: return ("Standalone (embedded) application");
	default: return ("Unknown");
	}
}

/**
 * display_elf_header - Displays the header file in stdout
 * @fp: File descripter
 */
void display_elf_header(FILE *fp)
{
	Elf64_Ehdr elf_header;

	if (fread(&elf_header, 1, sizeof(elf_header), fp) != sizeof(elf_header))
	{
		perror("fread");
		exit(1);
	}

	printf("ELF Header:\n");
	printf("  Magic:    ");
	print_hex_dump((const unsigned char *)elf_header.e_ident, EI_NIDENT);
	printf("  Class:                            ");
	printf("%s\n", elf_header.e_ident[EI_CLASS] ==
			ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                             ");
	printf("%s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                          ");
	printf("%d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                           ");
	printf("%s\n", get_os_abi_name(elf_header.e_ident[EI_OSABI]));
	printf("  ABI Version:                      ");
	printf("%d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                             ");
	printf("%s\n", get_type_name(elf_header.e_type));
	printf("  Entry point address:              ");
	printf("%#010x\n", (unsigned int)elf_header.e_entry);
}
