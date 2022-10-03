#include "main.h"

/**
 * _memcpy - cpies the memory area
 * @dest: destination
 * @src: source
 * @n: an unsigned integer
 *
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0 ; i < n ; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
