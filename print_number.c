#include "main.h"

/**
 * print_number - prints a given integer as series of characters
 * @list: the number argument to the _printf function
 * Return: the length of the number ptinted as if it were a string
 */

int print_number(va_list list)
{
	int i = 1022, to_print, len = 0;
	char numarray[1024];
	long int number = va_arg(list, long int);
	unsigned long int newnum;

	numarray[i + 1] = '\0';
	if (number == 0)
		numarray[i] = '0';
	if (number >= 0)
		newnum = (unsigned long int) number;
	else
		_putchar('-');
	newnum = (unsigned long int) (-1 * number);
	while (newnum > 0)
	{
		to_print = newnum % 10;
		numarray[i] = to_print + '0';
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
