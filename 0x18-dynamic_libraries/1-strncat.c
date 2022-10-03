#include "main.h"
/**
 * *_strncat - concatenates at least 'n' bytes of two strings
 * @dest: destination
 * @src:  source pointer
 * @n: bytes number
 * Return: nothing
*/

char *_strncat(char *dest, char *src, int n)
{

int d_len, i;
for (d_len = 0; dest[d_len] != '\0'; d_len++)
;

for (i = 0; i < n && src[i] != '\0'; i++)
	dest[d_len + i] = src[i];

/*Adding a null character to terminate at the end*/
dest[d_len + i] = '\0';

return (dest);
}
