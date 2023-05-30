#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct specifier - defines the specifier and the respective function
 *
 * @specifier: Specifier
 * @resp_func: a pointer to the function that handle the specifier
 */
typedef struct specifier
{
	char specifier;
	int (*resp_func)(va_list);
} specifier_t;


int print_char(va_list arg_p);
int print_string(va_list arg_p);
int print_percent(va_list arg_p);
int print_integer(va_list arg_p);
int print_binary(va_list arg_p);
int print_unsigned(va_list arg_p);
int print_octal(va_list arg_p);
int print_hexa_lower(va_list arg_p);
int print_hexa_upper(va_list arg_p);
int get_specifier_func(const char *format, va_list arg_p, int count);
int _printf(const char *format, ...);

#endif
