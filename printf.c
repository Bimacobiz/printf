#include <stddef.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
 * _printf - produces output according to a format.
 * @format: the string or character to print
 * Return:  the number of characters printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	int n = 0, strlen = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);
	if (format[0] == '\0')
		return (0);
	va_start(arg_list, format);

	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{_putchar(format[n]);
			strlen++;
		}
		else if (format[n] == '%' && format[n + 1] != '\0')
		{
			strlen += checkfun(format[n + 1], arg_list);
			n++;
		}
	}
	va_end(arg_list);
	return (strlen);
}

/**
 * checkfun - checks the next character and take appropriate action
 * @ch: the charactr to check
 * @arg_list: list of arguments from main function
 * Return: an integer value
 */
int checkfun(char ch, va_list arg_list)
{
	int nn = 0, ii;
	char *strr;
	char chaa;

	if (ch == '%')
	{
		_putchar('%');
		nn = 1;
		return (nn);
	}
	else if (ch == 'c')
	{
		chaa = (char) va_arg(arg_list, int);
		_putchar(chaa);
		nn = 1;
		return (nn);
	}
	else if (ch == 's')
	{strr = va_arg(arg_list, char *);
		if (strr == NULL)
			strr = "(null)";
		for (ii = 0; strr[ii] != '\0'; ii++)
		{
			_putchar(strr[ii]);
		}
		return (ii);
	}
	va_end(arg_list);
	return (nn);
}
