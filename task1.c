#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * printinteger - prints interger values
 * @format: the conversion specifier
 * @args: the argument list
 * Return: void
 */
void integers(const char *format, va_list args)
{
	int i, d;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
					d = va_arg(args, int);
					print_integer(d);
					break;
				case 'i':
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
