#include <main.h>
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int  _strlen(char *s)
{
	int t = 0;

	while (*s != '\0')
	{
		t++;
		s++;
	}

	return (t);
}

/**
 * _strncmp - Compare two strings up to a specified number of characters
 * @s1: input value
 * @s2: input value
 * @n: number of characters to compare
 *
 * Return: s1[t] - s2[t]
 */
int _strncmp(const char *s1, const char *s2, int  n)
{
	int t = 0;

	while (n > 0 && (s1[t] != '\0' || s2[t] != '\0'))
	{
		if (s1[t] != s2[t])
		{
			return (s1[t] - s2[t]);
		}

		t++;
		n--;
	}

	return (0);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int y = 0;
	int m = 0;

	while (*(src + y) != '\0')
	{
		y++;
	}
	for ( ; m < y ; m++)
	{
		dest[m] = src[m];
	}
	dest[y] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int t = 0;

	int y = 0;

	while (dest[t] != '\0')
	{
		t++;
	}
	while (src[y] != '\0')
	{
		dest[t] = src[y];
		t++;
		y++;
	}

	dest[t] = '\0';
	return (dest);
}
