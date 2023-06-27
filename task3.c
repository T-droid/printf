#include "main.h"

#define MAX 1024
/**
 * printXoxu - print octal, unsigned int and hexadecimal
 * @format: format specifier
 * @args: copy of the va_list
 * Return: void
 */
void printXoxu(const char *format, va_list args)
{
	unsigned int num;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '+' || *format == '#' || *format == ' ')
				print_flag(*format, *(++format))
			switch (*format)
			{
				case 'X':
					num = (unsigned int)va_arg(args, int);
					print_hexa(num, 'X', specifier);
					break;
				case 'x':
					num = (unsigned int)va_arg(args, int);
					print_hexa(num, 'x', &specifier);
					break;
				case 'o':
					num = (unsigned int)va_arg(args, int);
					print_octal(num);
					break;
				case 'u':
					num = (unsigned int)va_arg(args, int);
					print_integer(num);
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
 * print_octal - prints an octal number
 * @num: number to be printed in octal
 */
void print_octal(int num)
{
	char oct[MAX];
	int i = 0, rem;

	if (num == 0)
		_putchar('0');
	while (num > 0)
	{
		rem = num % 8;
		oct[i] = '0' + rem;
		num = num / 8;
		i++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(oct[i]);
		i--;
	}
	_putchar('\n');
}

/**
 * print_hexa - prints number in hexadecimal
 * @num: number to be printed in hexadecimal
 * @a: format
 * @f: function to determine the format of the number
 */
void print_hexa(int num, char a, char (*f)(char a))
{
	char hex[MAX], ch;
	int i = 0, rem;

	_putchar('0');
	_putchar('x');
	if (num == 0)
	{
		_putchar('0');
		_putchar('0');
	}

	ch = f(a);
	while (num > 0)
	{
		rem = rem % 16;

		if (rem < 10)
			hex[i] = rem + '0';
		else
			hex[i] = rem - 10 + ch;
		num = num / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(hex[i]);
		i--;
	}
	_putchar('\n');
}

/**
 * specifier - specifies the format of a hexadecimal
 * @a: format
 * Return: format specified
 */
char specifier(char a)
{
	if (a == 'X')
		return ('A');
	else if (a == 'x')
		return ('a');
}
