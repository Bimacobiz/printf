#include <stddef.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: the string or character to print
 * Return:  the number of characters printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	int n, strlen = 0;
	va_list arg_list;

	if (format == NULL)
		return (0);
	va_start(arg_list, format);

	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{_putchar(format[n]);
			strlen++;
		}
		else if (format[n] == '%')
		{
			n++;
			strlen += checkfun(format[n + 1], arg_list);
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
	char *strr, chaa;

	if (ch == '\0')
	{	_putchar('\0');
		nn = 0;
		return (nn);
	}

	if (ch == '%')
	{_putchar('%');
		nn = 1;
		return (nn);
	}
	else if (ch == 'c')
	{chaa = va_arg(arg_list, int);
		_putchar(chaa);
		nn = 1;
	}
	else if (ch == 's')
	{strr = va_arg(arg_list, char *);
		nn++;
		for (ii = 0; strr[ii] != '\0'; ii++)
		{
			_putchar(strr[ii]);

		}
		return (ii);
	}
	return (nn);
}
