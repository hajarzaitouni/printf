#include "main.h"

/**
 * print_binary - converted to unsigned int argument to binary
 * @arg_p: argument pointer
 * Return: converted binary number
 */

int print_binary(va_list arg_p)
{
	unsigned int n = va_arg(arg_p, unsigned int);
	char buffer[32];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		buffer[i] = '0';
		count++;
	}

	while (n > 0)
	{
		buffer[i] = (n % 2) + '0';
		n = n / 2;
		i++;
		count++;
	}
	for (i = count - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}
	return (count);
}

/**
 * print_unsigned - prints an unsigned number
 * @arg_p: argument pointer
 * Return: The number of printed characters
 */
int print_unsigned(va_list arg_p)
{
	unsigned int n = va_arg(arg_p, unsigned int);
	char buffer[32];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		buffer[i] = '0';
		count++;
	}

	while (n > 0)
	{
		buffer[i] = (n % 10) + '0';
		n = n / 10;
		i++;
		count++;
	}

	for (i = count - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}
	return (count);
}

/**
 * print_octal - prints an unsigned number in octal
 * @arg_p: argument pointer
 * Return: the number of printed characters
 */
int print_octal(va_list arg_p)
{
	unsigned int n = va_arg(arg_p, unsigned int);
	char buffer[32];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		buffer[i] = '0';
		count++;
	}

	while (n > 0)
	{
		buffer[i] = (n % 8) + '0';
		n = n / 8;
		i++;
		count++;
	}

	for (i = count - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}
	return (count);
}

/**
 * print_hexa_lower - prints an unsigned number in hexadecimal
 * @arg_p: argument pointer
 * Return: the number of printed characters
 */

int print_hexa_lower(va_list arg_p)
{
	unsigned int n = va_arg(arg_p, unsigned int);
	char buffer[32];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		buffer[i] = '0';
		count++;
	}

	while (n > 0)
	{
		int r = n % 16;/* r is the remainder */

		if (r < 10)
			buffer[i] = r + '0';
		else
			buffer[i] = (r - 10) + 'a';
		n = n / 16;
		i++;
		count++;
	}
	for (i = count - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}

	return (count);
}

/**
 * print_hexa_upper - prints an unsigned number in hexadecimal
 * @arg_p: argument pointer
 * Return: the number of printed characters
 */
int print_hexa_upper(va_list arg_p)
{
	unsigned int n = va_arg(arg_p, unsigned int);
	char buffer[32];
	int i = 0;
	int count = 0;

	if (n == 0)
	{
		buffer[i] = '0';
		count++;
	}

	while (n > 0)
	{
		int r = n % 16;/* r is the remainder */

		if (r < 10)
			buffer[i] = r + '0';
		else
			buffer[i] = (r - 10) + 'A';
		n = n / 16;
		i++;
		count++;
	}
	for (i = count - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}
	return (count);
}
