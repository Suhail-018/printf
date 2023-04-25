#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - prints output according to a format
 * @format: the format string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
putchar(va_arg(args, int));
count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
while (*str)
{
putchar(*str);
str++;
count++;
}
}
else if (*format == '%')
{
putchar('%');
count++;
}
else
{
putchar('%');
putchar(*format);
count += 2;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
