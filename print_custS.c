#include "main.h"

/**
 * print_custom_s - custom specifier to print unprintable string
 * @list: variable argument list from main function
 * Return: the length of the string printed
 */

int print_custom_s(va_list list)
{
	int len = 0, n;
	char *str = va_arg(list, char *);
	unsigned int unprintable;

	if (str == NULL)
		str = "(null)";
	while (str[n] != '\0')
	{
		if ((str[n] < 32 && str[n] > 0) || (str[n] >= 127))
		{	unprintable = 0 + str[n], print_custHEX(unprintable);
			len += 4, n++;
		       	continue;
		}
		_putchar(str[n]);
		n++, len++;
	}
	return (len);
}


int print_custHEX(unsigned int number)
{
	int i = 24, to_print, len = 0;
	char numarray [24];

	numarray[i - 1] = '\0';
	i--;
	_putchar('\\');
	_putchar('x');
	if (number == 0)
	{_putchar('0');
		return(1);
	}

	while (number > 0)
	{
		to_print = number % 16;
		if (to_print == 15)
			numarray[i - 1] = 'F';
		else if (to_print == 14)
			numarray[i - 1] = 'E';
		else if (to_print == 13)
			numarray[i - 1] = 'D';
		else if (to_print == 12)
			numarray[i - 1] = 'C';
		else if (to_print == 11)
			numarray[i - 1] = 'B';
		else if (to_print == 10)
			numarray[i - 1] = 'A';
		else
			numarray[i - 1] = to_print + '0';
		number /= 16;
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
