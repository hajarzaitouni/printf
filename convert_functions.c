#include "main.h"

/**
 * print_binary - converted to unsigned int argument to binary
 * @arg_p: argument pointer
 * Return: converted binary number
 */

int print_binary(va_list arg_p)
{
	unsigned long int n = va_arg(arg_p, unsigned long int);
	char buffer[32];
	int i = sizeof(buffer) - 1, count = 0;
	unsigned long int j;
	int extra_zeros = 1;

	if (n == 0)
		return (write(1, "0", 1));

	buffer[i] = '\0';
	while (n > 0)
	{
		if (n % 2 == 1)
			buffer[--i] = '1';
		else
			buffer[--i] = '0';
		n = n / 2;
	}
	for (j = i; j < sizeof(buffer); j++)
	{
		if (extra_zeros == 1 && buffer[j] == '0')
			continue;
		extra_zeros = 0;
		count += write(1, &buffer[j], 1);
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
	unsigned int i = sizeof(buffer) - 1;
	int count = 0;

	if (n == 0)
		return (write(1, "0", 1));

	buffer[i] = '\0';
	while (n > 0)
	{
		buffer[--i] = (n % 10) + '0';
		n = n / 10;
	}

	for ( ; i < sizeof(buffer); i++)
	{
		write(1, &buffer[i], 1);
		count++;
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
	unsigned long int n = va_arg(arg_p, unsigned long int);
	char buffer[32];
	unsigned long int i = sizeof(buffer) - 1, count = 0;

	if (n == 0)
		return (write(1, "0", 1));
	buffer[i] = '\0';
	while (n > 0)
	{
		int r = n % 16;/* r is the remainder */

		if (r < 10)
			buffer[--i] = r + '0';
		else
			buffer[--i] = (r - 10) + 'a';
		n = n / 16;
	}
	for ( ; i < sizeof(buffer); i++)
	{
		count += write(1, &buffer[i], 1);
	}

	return (count);
}
