#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
   int len;
   int len2;
   unsigned int ui = 183524517;

_printf("Character:[%c]\n", 'H');
 printf("Character:[%c]\n", 'H');
 _printf("String:[%s]\n", "I am a string !");
 printf("String:[%s]\n", "I am a string !");
 len = _printf("Percent:[%%]\n");
 len2 = printf("Percent:[%%]\n");
 printf("Percent:%d\n",len);
 printf("Percent:%d\n",len2);
 _printf("[%d, %i]\n", len, len2);
 _printf("Unsigned:[%u]\n", ui);
 printf("Unsigned:[%u]\n", ui);
 _printf("Unsigned octal:[%o]\n", ui);
 printf("Unsigned octal:[%o]\n", ui);
 _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
 printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

 return (0);
}
