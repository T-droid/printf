/**
 *_printf - function that produces output according to a format
 *@format:  is a character string
 *
 *Return: the number of characters printed
 */
#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list lists;

	va_start(lists, format);
	int i = 0;

	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			if (*format == 'c')
			{
				putchar(va_arg(lists, int));
				i++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(lists, char *);

				while (*s)
				{
					putchar(*s);
					s++;
					i++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				i++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				i += 2;
			}
		}
		else
		{
			putchar(*format);
				i++;
		}
		format++;
	}
	va_end(lists);
	return (i);
}
