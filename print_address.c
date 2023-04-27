#include "main.h"

/**
 * print_address - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int print_address(va_list val)
{
	void *p;
	char *s = "(nil)";
	long int a;
	int b;
	int i;

	p = va_arg(val, void*);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	b = print_hex_more(a);
	return (b + 2);
}
