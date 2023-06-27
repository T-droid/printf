#include "main.h"

/**
 * print_string - prints strings
 * @format: specifies the format
 * @args: the copy of a va_list
 */
void print_string(const char *format, va_list args)
{
	char *str;
	int i, ascii;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'S')
			{
				str = va_arg(args, char*);
				i = 0;
				while (str[i] != '\0')
				{
					ascii = str[i];
					if ((ascii < 32 && ascii > 0) || ascii >= 127)
					{
						_putchar('\\');
						_putchar('x');
						_putchar('0');
						print_hexa(ascii, 'X', &specifier);
					}
					else
						_putchar(str[i]);
					i++;
				}
			}
		}
		format++;
	}
	_putchar('\n');
}
