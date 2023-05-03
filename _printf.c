#include "main.h"
/**
 * _printf - prints based on formats
 * @format: the input string
 * Return: the length of the string printed;
 */
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
			_putchar(format[n]), len++;
		if (format[n] == '%' && (format[n + 1] == '\0' || format[n + 1] == ' '))
			return (-1);
		else if (format[n] == '%' && format[n + 1] == '%')
			_putchar('%'), len++, n += 1;
		else if (format[n] == '%' && format[n + 1] == 'c')
			len += print_char(list), n += 1;
		else if (format[n] == '%' && format[n + 1] == 's')
			len += print_string(list), n += 1;
		else if (format[n] == '%' && (format[n + 1] == 'd' || format[n + 1] == 'i'))
			len += print_number(list), n++;
		else if (format[n] == '%' && (format[n + 1] == 'b'))
			len += print_binary(list), n++;
		else if (format[n] == '%' && (format[n + 1] == 'o' || format[n + 1] == 'x' || format[n + 1] == 'X' || format[n + 1] == 'u'))
			len += choose_fun(list, format[n + 1]), n++;
		else if (format[n] == '%' && format[n + 1] == 'S')
			len += print_custom_s(list), n++;
		else if (format[n] == '%' && format[n + 1] == 'p')
		{	_putchar('0'), _putchar('x'), n++, len += 2;
			len += choose_fun(list, 'x');
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

	if (str == NULL)
		str = "(null)";

	while (str[len] != '\0')
	{
		_putchar(str[len]);
		len++;
	}

	return (len);
}
