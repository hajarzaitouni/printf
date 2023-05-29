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
 * @resp_func: a pointer to the function that handel the specifier
 */
typedef struct specifier
{
	char specifier;
	int (*resp_func)(va_list);
}
specifier_t;


int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap);
int _printf(const char *format, ...);

#endif
