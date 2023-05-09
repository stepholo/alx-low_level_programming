#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

/* Elf Functions*/
void _close_elf(int _elf);
void printf_entry(unsigned long int e_entry, unsigned char *e_ident);
void printf_type(unsigned int e_type, unsigned char *e_ident);
void printf_abi(unsigned char *e_ident);
void printf_osabi(unsigned char *e_ident);
void printf_version(unsigned char *e_ident);
void printf_data(unsigned char *e_ident);
void printf_class(unsigned char *e_ident);
void printf_magic(unsigned char *e_ident);
void _check_elf(unsigned char *e_ident);

#endif
