#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

int _putchar(char c);
int print_char(va_list list);
int print_string(va_list list);
int _printf(const char *format, ...);

#endif
