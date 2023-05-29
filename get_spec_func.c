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
		{'\0', NULL}
	};
	int i, size;

	i = 0;
	size = sizeof(types) / sizeof(types[0]);

	while (i < size)
	{
		if (types[i].specifier == *format)
		{
			count += types[i].resp_func(arg_p);
			break;
		}
		i++;
	}

	return (count);
}
