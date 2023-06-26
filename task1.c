#include "main.h"

/**
 * printinteger - prints interger values
 * @format: the conversion specifier
 * @args: the argument list
 * Return: void
 */
void printinteger(const char *format, va_list args)
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
				case 'd' :
					d = va_arg(args, int);
					write(1, &d, sizeof(int));
					break;
				case 'i' :
					i = va_arg(args, int);
					write(1, &i, sizeof(int));
					break;
				default :
					break;
			}
		}
		format++;
	}
	va_end(args);
}
