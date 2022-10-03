#include "main.h"
/**
 * _strcmp - writes the character c to stdout
 * @s1: The character to print
 * @s2: pointer to print
 * Return: On success 1.
 * On error, -1 is returned
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] == s2[a] && s1[a] && s2[a])
	{
		a++;
	}

	return (s1[a] - s2[a]);
}
