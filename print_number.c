#include "main.h"

/**
 * print_number - prints a given integer as series of characters
 * @list: the number argument to the _printf function
 * Return: the length of the number ptinted as if it were a string
 */

int print_number(va_list list)
{
	int i = 1024, to_print, len = 0;
	char numarray[1024];
	int number = va_arg(list, int);
	int newnum = number;

	numarray[i] = '\0';
	if (number == 0)
	{	numarray[i - 1] = '0';
		len = 1;
	}
	if (number < 0)
	{
		_putchar('-');
		newnum = (-1 * number);
	}
	while (newnum > 0)
	{
		to_print = newnum % 10;
		numarray[i - 1] = to_print + '0';
		newnum /= 10;
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
