#include "main.h"

/**
 * print_env - Display the environment variables
 *
 */

void print_env(void)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
