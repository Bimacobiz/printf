#include "main.h"
/**
 * choose_fun - choose appropriate function to call
 * @list: argument list from the main function
 * @c: character that determines the function to call
 * Return: the length of the number printed
 */ 

int choose_fun(va_list list, char c)
{
	if (c == 'o')
		return (print_octal(list));
	else if (c == 'u')
		return (print_un_dec(list));
	else if (c == 'x')
		return (print_hex(list));
	else if (c == 'X')
		return (print_HEXA(list));
	return (0);
}

/**
 * print_octal - print the number in base 8
 * @list: number argument
 * Return: the lenght of the number printed
 */

int print_octal(va_list list)
{
	int i = 1024, to_print, len = 0;
	char numarray [1024];
	unsigned int number = va_arg(list, unsigned int);

	numarray[i - 1] = '\0';
	i--;
	if (number == 0)
		numarray[i] = '0';
	while (number > 0)
	{
		to_print = number % 8;
		numarray[i - 1] = to_print + '0';
		number /= 8;
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

/**
 * print_un_dec - print the number in base 10
 * @list: number argument
 * Return: the lenght of the number printed
 */

int print_un_dec(va_list list)
{
	int i = 1024, to_print, len = 0;
	char numarray [1024];
	unsigned int number = va_arg(list, unsigned int);

	numarray[i--] = '\0';
	if (number == 0)
	{	_putchar('0');
		return(1);
	}
	while (number > 0)
	{
		to_print = number % 10;
		numarray[i - 1] = to_print + '0';
		number /= 10;
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

/**
 * print_hex - print the number in base 16(abcdef)
 * @list: number argument
 * Return: the lenght of the number printed
 */

int print_hex(va_list list)
{
	int i = 1024, to_print, len = 0;
	char numarray [1024];
	unsigned int number = va_arg(list, unsigned int);

	numarray[i - 1] = '\0';
	i--;
	if (number == 0)
	{	_putchar('0');
		return(1);
	}
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

	while (numarray[i])
	{
		_putchar(numarray[i]);
		i++;
		len++;
	}
	return (len);
}

/**
 * print_HEXA - print the number in base 16(ABCDEF)
 * @list: number argument
 * Return: the lenght of the number printed
 */

int print_HEXA(va_list list)
{
	int i = 1024, to_print, len = 0;
	char numarray [1024];
	unsigned int number = va_arg(list, unsigned int);

	numarray[i - 1] = '\0';
	i--;
	if (number == 0)
	{	_putchar('0');
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
