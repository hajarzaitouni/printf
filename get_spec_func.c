#include "main.h"

/**
 * get_specifier_func - handle the specifier and the correponding function
 *
 * @format: a pointer to string
 * @arg_p: argument pointer
 * @count: iterator of type integer
 * Return: the number of printed charcters
 */

int get_specifier_func(const char *format, va_list arg_p, int count)
{
	specifier_t types[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_integer},
		{'i', print_integer},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexa_lower},
		{'X', print_hexa_upper},
		{'\0', NULL}
	};
	int i;

	i = 0;
	while (types[i].specifier != '\0')
	{
		if (types[i].specifier == *format)
		{
			count += types[i].resp_func(arg_p);
			break;
		}
		i++;
	}
	if (types[i].specifier == '\0')
		return (-1);

	return (count);
}
