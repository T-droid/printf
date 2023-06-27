#include "main.h"

/**
 * lengths - determines whether long or short
 * @c: h or l
 * Return: 1 if long and -1 if short
 */
int lengths(char c)
{
	int i;

	if (c == 'l')
		i = 1;
	else if (c == 'h')
		i = -1;
	return (i);
}
