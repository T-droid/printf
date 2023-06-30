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
	va_list args, args2;
	int count = 0;
	

	va_start(args, format);
	va_copy(args2, args);

	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			if (*format == 'c')
			{
				_putchar(va_arg(args, int));
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					_putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
				count += integers(*format, args);

			else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
			{
				count += printXoxu(*format, args2);
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
				count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
