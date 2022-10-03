#include "main.h"

/**
 * _memset - sets the memory pointyed to with char
 * @s: the address in memory to fill
 * @b: the char variable to fill in the memory
 * @n: the memory size
 *
 * Return: pointer to string
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int unt;

	for (unt = 0; unt < n; unt++)
	s[unt] = b;

	return (s);
}
