#include "main.h"
/**
 * get_size - calculates the size which the argument is casted
 * @format: the formatted string on which the argument is printed
 * @i: the list of arguments that should be printed
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
