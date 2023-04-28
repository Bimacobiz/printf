#include "main.h"

int _printf(const char *format, ...)
{
	int n = 0, len = 0;
	va_list list;

	if (format == NULL)
		return (-1);


	va_start(list, format);
	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] != '%' && format[n])
		{
			_putchar(format[n]);
			len++;
		}
		if (format[n] == '%' && format[n + 1] == '\0')
			return (-1);
		else if (format[n] == '%' && format[n + 1] == '%')
		{
			_putchar('%');
			len++;
			n += 1;
		}
		else if (format[n] == '%' && format[n + 1] == 'c')
		{
			len += print_char(list);
			n += 1;
		}
		else if (format[n] == '%' && format[n + 1] == 's')
		{
			len += print_string(list);
			n += 1;
		}
	}
	va_end(list);
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
	if (!ch)
		return (-1);

	_putchar(ch);
	return (0);
}

/**
 * print_string - it is afunction that prints strings
 * @list: list of arguments
 * Return: int
 */

int print_string(va_list list)
{
	int len = 0;
	char *str = va_arg(list, char []);

	if (!str)
		return (-1);

	for (len = 0; *str != '\0'; len++)
		_putchar(str[len]);

	return (len + 1);
}
