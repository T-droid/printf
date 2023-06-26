/**
 *_printf - produces output according to a format
 *
 */Returns: the number of characters print

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
	va_list lists;
	int i = 0;

	va_start(lists, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
		format++;
		switch (*format)
		{
			case 'c':
				{
					char c = (char)va_arg(lists, int);
					
					putchar(c);
					i++;
					break;
				}
			case 's':
                {
			char *str = va_arg(lists, char *);
			
			fputs  (str, stdout);
			i += strlen(str);
			break;
		}
			case '%':
                {
			putchar('%');
			i++;
			break;
		}
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
	return i;
}
