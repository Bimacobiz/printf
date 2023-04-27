#include "main.h"

/**
 * print_char - prints a character from the string
 * @val: arguments given
 * Return: 1
 */

int print_char(va_list val)
{
	char cha;
	int k = 8;
	int h = 9;

	if (h > k)
		k += 2;

	cha = va_arg(val, int);
	_putchar(cha);
	return (1);
}
