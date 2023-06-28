/**
 *convert_to_binary - prints binary of unsigned integer number
 *@b: number to be converted to binary
 *return: nothing
 */
#include "main.h"
#include <stdio.h>
#include <stdarg.h>

void convert_to_binary(const char *format, ...)
{
	va_list args;
	int count = 0;
	int  b;


	va_start(args, format);
	(*format == 'b');
	{
		unsigned int num = va_arg(args, unsigned int);
		int bits = sizeof(num) * 8;
		char binary[bits + 1];

		binary[bits] = '\0';

		while (int i = bits - 1; i >= 0)
		{
			binary[i] = (num & 1) ? '1' : '0';
			num >>= 1;
		}i--
		printf("%s", binary);
		count++;
	}
	format++;

va_end(args);
return (count);
}
