#include "main.h"
/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @arg: array of entered words
 */

void _setenv(char **arg)
{
	int m, y, f;

	if (!arg[1] || !arg[2])
	{
		perror(_getenv("_"));
		return;
	}

	m = 0;
	while (environ[m])
	{
		y = 0;
		if (arg[1][y] == environ[m][y])
		{
			for (; arg[1][y]; y++)
			{
				if (arg[1][y] != environ[m][y])
					break;
			}
			if (arg[1][y] == '\0')
			{
				f = 0;
				for (; arg[2][f]; f++)
				{
					environ[m][y + 1 + f] = arg[2][f];
				}
				environ[m][y + 1 + f] = '\0';
				return;
			}
		}
		m++;
	}
	if (!environ[m])
	{

		environ[m] = _concat(arg[1], "=", arg[2]);
		environ[m + 1] = '\0';

	}
}

/**
 * _unsetenv - Remove an environment variable
 * @arg: array of entered words
 */

void _unsetenv(char **arg)
{
	int m, y;

	if (!arg[1])
	{
		perror(_getenv("_"));
		return;
	}

	m = 0;
	while (environ[m])
	{
		j = 0;
		if (arg[1][y] == environ[m][y])
		{
			for (; arg[1][y]; y++)
			{
				if (arg[1][y] != environ[m][y])
					break;
			}
			if (arg[1][y] == '\0')
			{
				free(environ[m]);
				environ[m] = environ[m + 1];
				for (; environ[m]; m++)
				{
					environ[m] = environ[m + 1];
				}
				return;
			}
		}
		m++
	}
}
