#include "main.h"
#include <stddef.h>
/**
* _strchr - locates a character in a string
* @s: the string variable
* @c: the character to look for
*
* Return: a pointer to a char
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (!c ? s : NULL);
}
