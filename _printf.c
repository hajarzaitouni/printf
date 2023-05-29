#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: a pointer to string
 * @...: a variable of arguments
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list arg_p;

	va_start(arg_p, format);

	while (format && *format != '\0')
	{
		if (*format == '%')
		{
			format++;/* move to the next character */
			count = get_specifier_func(format, arg_p, count);
		}
		else
			count += write(1, format, sizeof(char));
		format++;
	}

	va_end(arg_p);

	return (count);
}
