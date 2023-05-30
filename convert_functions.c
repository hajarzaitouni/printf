#include "main.h"

/**
 * print_binary - converted to unsigned int argument to binary
 * @arg_p: argument pointer
 * Return: converted binary number
 */

int print_binary(va_list arg_p)
{
	unsigned int n = va_arg(arg_p, unsigned int);
	char array[32];
	int i = sizeof(array) - 1, count = 0;
	unsigned long int j;
	int extra_zeros = 1;

	if (n == 0)
		return (write(1, "0", 1));

	array[i] = '\0';
	while (i > 0)
	{
		i--;
		if (n % 2 == 1)
			array[i] = '1';
		else
			array[i] = '0';
		n = n / 2;
	}
	for (j = i; j < sizeof(array); j++)
	{
		if (extra_zeros == 1 && array[j] == '0')
			continue;
		extra_zeros = 0;
		count += write(1, &array[j], 1);
	}
	return (count);
}
