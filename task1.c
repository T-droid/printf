#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * integers - prints interger values
 * @format: the conversion specifier
 * @args: the argument list
 * Return: void
 */
void integers(const char *format, va_list args)
{
	int i, d, len;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '+' || *format == '#' || *format == ' ')
				print_flag(*format, *(++format));
			else if (*format == 'h' || *format == 'l')
				len = lengths(*format);
			switch (*format)
			{
				case 'd':
					if (len == 1)
						d = va_arg(args, long);
					else if (len == -1)
						d = va_arg(args, short);
					else
						d = va_arg(args, int);
					print_integer(d);
					break;
				case 'i':
					if (len == 1)
						i = va_arg(args, long);
					else if (len == -1)
						i = va_arg(args, short);
					else
						i = va_arg(args, int);
					print_integer(i);
					break;
				default:
					break;
			}
		}
		format++;
	}
	va_end(args);

}


/**
 * print_integer - prints integers using putchar
 * @i: integer to be printed
 */
void print_integer(int i)
{
	if (i < 0)
	{
		_putchar('-');
		i = -i;
	}

	if (i == 0)
	{
		_putchar('0');
		return;
	}
	print_digits(i);
}

/**
 * print_digits - prints number digits recursively using putchar
 * @num: number whose digits are to be printed
 */
void print_digits(int num)
{
	if (num == 0)
		return;
	print_digits(num / 10);
	_putchar('0' (num % 10));
}
