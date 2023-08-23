#include "main.h"
/**
 * _concat - concats 3 strings in a newly allocated memory
 * @n: first string
 * @s: second string
 * @v: Third string
 * Return: pointer to the new string
 */
char *_concat(char *n, char *s, char *v)
{
	char *res;
	int len1, len2, len3, m, y;

	len1 = _strlen(n);
	len2 = _strlen(s);
	len3 = _strlen(v);

	res = malloc(len1 + len2 + len3 + 1);
	if (!res)
		return (NULL);
	m = 0;
	while (n[m])
	{
		res[m] = n[m];
		m++;
	}
	y = m;

	while (s[m])
	{
		res[y + m] = s[m];
		m++;
	}

	y += m;

	while (v[m])
	{
		res[y + m] = v[m];
		m++;
	}

	y += m;

	res[y] = '\0';

	return (res);
}

/**
 * _getenv - get an environment variable
 * @n: name of the environment variable
 *
 * Return: string of value
 */
char *_getenv(const char *n)
{
	int m, y;
	char *v;

	if (!n)
		return (NULL);
	m = 0;
	while (environ[m])
	{
		if (n[y] == environ[m][y])
		{
			for (y = 0; n[y]; y++)
			{
				if (n[y] != environ[m][y])
					break;
			}
			if (n[y] == '\0')
			{
				v = (environ[m] + y + 1);
				return (v);
			}
		}
		m++;
	}
	return (0);
}
