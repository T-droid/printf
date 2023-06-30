#include "main.h"

#define MAX 1024
/**
 * printXoxu - print octal, unsigned int and hexadecimal
 * @format: format specifier
 * @args: copy of the va_list
 * Return: void
 */
int printXoxu(char format, va_list args)
{
	unsigned int num;
	int count = 0;

	switch(format)
	{
		case 'u':
			num = (unsigned int)va_arg(args, unsigned int);
			count += print_integer(num);
			break;
		case 'o':
			num = va_arg(args, unsigned int);
			printf("%d\n", num);
			count += print_octal(num);
			break;
		case 'x':
			num = va_arg(args, unsigned int);
			count += print_hexa(num, 'x', specifier);
			break;
		case 'X':
			num = va_arg(args, unsigned int);
			count += print_hexa(num, 'X', specifier);
			break;
		default :
			break;
	}
	return (count);
}

/**
 * print_octal - prints an octal number
 * @num: number to be printed in octal
 */
int print_octal(int num)
{
	char oct[MAX];
	int i = 0, rem;
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		num *= -1;
	}

	if (num == 0)
	{
		_putchar('0');
		count++;
	}
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
		count++;
		i--;
	}
	return (count);
}

/**
 * print_hexa - prints number in hexadecimal
 * @num: number to be printed in hexadecimal
 * @a: format
 * @f: function to determine the format of the number
 */
int print_hexa(int num, char a, char (*f)(char a))
{
	char hex[MAX], ch;
	int i = 0, rem, count = 0;

	if (num < 0)
		num *= -1;
	if (num == 0)
	{
		_putchar('0');
		count++;
		_putchar('0');
		count++;
	}

	ch = f(a);
	while (num > 0)
	{
		rem = rem % 16;

		if (rem < 10)
			hex[i] = rem + '0';
		else
		{
			if (ch == 'A')
				hex[i] = rem - 10 + 'A';
			else
				hex[i] = rem - 10 + 'a';
		}
		num = num / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		_putchar(hex[i]);
		count++;
		i--;
	}
	_putchar('\n');
	return (count);
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
	return ('a');
}
