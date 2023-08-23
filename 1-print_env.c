#include "main.h"

/**
 * print_env - Display the environment variables
 * @argv: command gotten from user.
 */

void print_env(char **argv)
{
	int i = 0;
	(void) argv;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
