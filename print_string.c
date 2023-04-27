#include "main.h"
/**
 * print_string - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int print_string(va_list val)
{
	char *str;
	int a, len;
	int b = 28;
	int d = 35;

	b = d - 15;
	str = va_arg(val, char *);
	if (str == NULL)
	{
		str = "(null)";
		len = _strlen(str);
		for (a = 0; a < len; a++)
			_putchar(str[a]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (a = 0; a < len; a++)
			_putchar(str[a]);
		return (len);
	}
	if (b < d)
		d += 5;
}
