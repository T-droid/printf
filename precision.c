#include "main.h"

/**
 * precision - handles precision for non custom conversion specifiers
 * @args: copy of the va_list
 * @format: format specifier
 */
void precision(const char *format, va_list args)
{
	int precision, integerpart, digit;
	double num, fraction;

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			precision = 6;
			if (*format == '.')
			{
				format++;
				precision = 0;

				while (*format >= '0' && *format <= '9')
				{
					precision = precision * 10 + (*format - '0');
					format++;
				}
			}
			switch (*format)
			{
				case 'f':
					num = va_arg(args, double);
					fraction = num - (int)num;

					integerpart = (int)num;
					print_integer(integerpart);

					if (precision >= 0)
					{
						_putchar('.');
						while (precision > 0)
						{
							fraction *= 10;
							digit = (int)fraction;
							_putchar('0' + digit);
							fraction -= digit;
							precision--;
						}
					}
					break
				default :
						break;
			}
		}
		format++;
	}
	va_end(args);
}
