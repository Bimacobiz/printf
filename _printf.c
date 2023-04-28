#include "main.h"

int _printf(const char *format, ...)
{
	int n = 0, len = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			_putchar(format[n]);
			len++;
		}
		if (format[n] == '%' && format[n + 1] == '\0')
			return (-1);
		if (format[n] == '%' && format[n + 1] == '%')
		{
			_putchar('%');
			len++;
			n++;
		}
		if (format[n] == '%' && format[n + 1] == 'c')
		{
			len += print_char(list);
			n++;
		}
		if (format[n] == '%' && format[n + 1] == 's')
		{
			len += print_string(list);
			n++;
		}
	}
	return (len);
}

/**
 * print_char - a function that prints a character
 * @list: a list of arguments
 * Return: integer value.
 */

int print_char(va_list list)
{
	char ch = va_arg(list, int);

	_putchar(ch);
	return (1);
}

/**
 * print_string - it is afunction that prints strings
 * @list: list of arguments
 * Return: int
 */

int print_string(va_list list)
{
	int len = 0;
	char *str = va_arg(list, char *);

	for (len = 0; *str != '\0'; len++)
		_putchar(str[len]);

	return (len);
}
