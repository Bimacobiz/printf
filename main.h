#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

int _putchar(char c);
int print_char(va_list list);
int print_string(va_list list);
int _printf(const char *format, ...);
int print_number(va_list list);
int print_binary(va_list list);
int choose_fun(va_list, char c);
int print_octal(va_list list);
int print_un_dec(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);

#endif
