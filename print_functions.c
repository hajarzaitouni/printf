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
		return (write(1, "(null)", 6));
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

int print_percent(__attribute__((unused)) va_list arg_p)
{
	return (write(1, "%", sizeof(char)));
}

/**
 * print_integer - prints an integer number
 * @arg_p: argument pointer
 * Return: the number of printed numbers
 */

int print_integer(va_list arg_p)
{
	long int num = va_arg(arg_p, int);
	char buffer[30];
	int len = 0, isnegative = 0;
	int i = sizeof(buffer) - 1;

	if (num < 0)
	{
		isnegative = 1;
		num = (-1) * num;
	}

	do {
		buffer[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	} while (num > 0);

	if (isnegative)
	{
		buffer[i] = '-';
		i--;
	}

	len = write(1, &buffer[i + 1], sizeof(buffer) - i - 1);

	return (len);
}

/**
 * print_binary - converted to unsigned int argument to binary
 * @arg_p: argument pointer
 * Return: converted binary number
 */

int print_binary(va_list arg_p)
{
	unsigned int n = va_arg(arg_p, unsigned int);
	char array[32];
	int i = sizeof(array) - 1, j, count = 0;
	int extra_zeros = 1;

	if (n == 0)
		return (write(1, "0", 1));

	array[i] = '\0';
	while (i > 0)
	{
		i--;
		array[i] = ((n % 2) ? '1' : '0');
		n = n / 2;
	}

	for (j = i; j < 32; j++)
	{
		if (extra_zeros == 1 && array[j] == '0')
			continue;
		extra_zeros = 0;

		count += write(1, &array[j], 1);
	}

	return (count);
}
