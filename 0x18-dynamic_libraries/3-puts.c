#include "main.h"
/**
 * _puts- prints string
 *
 *@str: string variable
 * Return: Always 0.
 */
void _puts(char *str)
{
	int in = 0;

	while (*(str + in))
	{
		_putchar(*(str + in));
		in++;
	}
	_putchar('\n');
}
