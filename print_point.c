#include "main.h"

/**
 * print_point - print memory address
 * @list: variable argument list from the main function
 * Return: the length of the hexadeciaml address printed
 */

int print_point(va_list list)
{
	int i = 1024, to_print, len = 0;
	char numarray [1024];
	unsigned long number;
	void *pointer = va_arg(list, void *);

	numarray[i - 1] = '\0';
	i--;
	if (pointer == NULL)
	{       _putchar('('), _putchar('n'), _putchar('i'), _putchar('l');
		_putchar(')'), len += 5;
		return (len);
	}
	number = (unsigned long)pointer;
	while (number > 0)
	{
		to_print = number % 16;
		if (to_print == 15)
			numarray[i - 1] = 'f';
		else if (to_print == 14)
			numarray[i - 1] = 'e';
		else if (to_print == 13)
			numarray[i - 1] = 'd';
		else if (to_print == 12)
			numarray[i - 1] = 'c';
		else if (to_print == 11)
			numarray[i - 1] = 'b';
		else if (to_print == 10)
			numarray[i - 1] = 'a';
		else
			numarray[i - 1] = to_print + '0';
		number /= 16;
		i--;
	}
	_putchar('0'), _putchar('x');
	while (numarray[i])
	{
		_putchar(numarray[i]);
		i++;
		len++;
	}
	return (len + 2);
}
