#include "main.h"

/**
 * print_binary - converts an unsigned int to binary
 * and then prints it out
 * @list: expected unsigned int argument
 * Return: returns the length of the binary
 */

int print_binary(va_list list)
{
	int i = 1024, to_print, len = 0;
	char numarray[1024];
	unsigned int number = va_arg(list, unsigned int);

	numarray[i] = '\0';
	if (number == 0)
	{
		_putchar('0');
		return (1);
	}

	while (number > 0)
	{
		to_print = number % 2;
		numarray[i] = to_print + '0';
		number /= 2;
		i--;
	}

	while (numarray[i])
	{
		_putchar(numarray[i]);
		i++;
		len++;
	}
	return (len);
}
