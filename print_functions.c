#include "main.h"

/**
 * print_char - prints a character
 * @arg_p: argument pointer
 * Return: the number of printed charcter
 */

int print_char(va_list arg_p)
{
	char c = va_arg(arg_p, int);

	return (write(1, &c, sizeof(char)));
}

/**
 * print_string - prints a string
 * @arg_p: argument pointer
 * Return: the lenght of string
 */

int print_string(va_list arg_p)
{
	int len = 0;
	const char *str = va_arg(arg_p, char *);

	if (str == 0)
		str = "(null)";
	while (*str != '\0')
	{
		len += write(1, str, sizeof(char));
		str++;
	}
	return (len);
}

/**
 * print_percent - prints the percent character "%"
 * @arg_p: argument pointer
 * Return: the number of printed charcters
 */

int print_percent( __attribute__((unused)) va_list arg_p)
{
	return (write(1, "%", sizeof(char)));
}
