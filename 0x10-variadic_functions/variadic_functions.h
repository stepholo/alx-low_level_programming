#ifndef VARIADIC_FUNCTION_H
#define VARIADIC_FUNCTION_H

/**
 * File: variadic_function.h
 * Desc: Contains function prototypes for variadic funtion
 */

#include <stdarg.h>

/**
 * struct printer - A new struct type defining a printer
 * @symbol: A symbol representing data type.
 * @print: A function pointer to a function that prints a 
 * data type corresponding to symbol
 */
typedef struct printer
{
	char *symbol;
	void (*print)(va_list arg);

} printer_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
