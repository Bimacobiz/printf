#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: the string or character to print
 * @Return:  the number of characters printed
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
	char *str;
	int n;
	char cha;
        int i;
        int strlen = 0;
        va_list arg_list;
        if (format == NULL)
                return (0);
        va_start(arg_list, format);
        for (n = 0; format[n] != '\0'; n++)
        {
		if (format[n] != '%')
		{
			_putchar(format[n]);
			strlen++;
		}
		else if (format[n] == '%')
		{
			if (format[n + 1] == '%')
			{
				_putchar('%');
				strlen++;
				n++;
			}
			else if (format[n + 1] == 'c')
			{
				cha = va_arg(arg_list, int);
				_putchar(cha);
				strlen++;
				n++;
			}
			else if (format[n + 1] == 's')
			{
				str = va_arg(arg_list, char *);
				n++;
				for (i = 0; str[i] != '\0'; i++)
				{
					_putchar(str[i]);
					strlen++;
				}
			}
		}
	}
	va_end(arg_list);
	return (strlen);
}
