/**
 *print_binary - prints binary of unsigned integer number
 *@num: number to be converted to binary
 *return: nothing
 */
#include "main.h"
#include <stdio.h>
#include <stdarg.h>

void print_binary(unsigned int num)
{
	if (num > 1)
		print_binary(num / 2);
	putchar('0' + num % 2);
}
