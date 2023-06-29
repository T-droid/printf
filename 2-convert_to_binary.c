/**
 *convert_to_binary - prints binary of unsigned integer number
 *@b: number to be converted to binary
 *return: nothing
 */
#include "main.h"
#include <stdio.h>
#include <stdarg.h>

void convert_to_binary(unsigned int num)
{
    int bits = sizeof(num) * 8;
    char binary[bits + 1];
    int i;

    binary[bits] = '\0';

    i = bits - 1;
    while (i >= 0)
    {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1;
        i--;
    }

    printf("%s", binary);
}

