#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * integers - prints interger values
 * @format: the conversion specifier
 * @args: the argument list
 * Return: void
 */
int integers(char format, va_list args)
{
	int d, i, count = 0;
	switch(format)
	{
		case 'd':
			d = va_arg(args, int);
			count += print_integer(d);
			break;
		case 'i':
			i = va_arg(args, unsigned int);
			count += print_integer(i);
			break;
		default:
			break;
	}
	return (count);

}


/**
 * print_integer - prints integers using putchar
 * @i: integer to be printed
 */
int print_integer(int i)
{
	int count = 0;

	if (i < 0)
	{
		_putchar('-');
		count++;
		i = -i;
	}

	if (i == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}
	count += print_digits(i);
	return (count);
}

/**
 * print_digits - prints number digits recursively using putchar
 * @num: number whose digits are to be printed
 */
int print_digits(int num)
{
	int count = 0;

	if (num == 0)
		return (count);
	print_digits(num / 10);
	_putchar('0' + (num % 10));
	count++;
	return (count);
}
