#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);

int lengths(char c);
void precision(const char *format, va_list args);
void print_flag(char a, char b);
int integers(char format, va_list args);
int print_integer(int i);
int print_digits(int num);
int printXoxu(char format, va_list args);
int print_octal(int num);
int print_hexa(int num, char a, char (*f)(char a));
char specifier(char a);
void print_string(const char *format, va_list args);


void convert_to_binary(unsigned int num);

#endif /* MAIN_H */
