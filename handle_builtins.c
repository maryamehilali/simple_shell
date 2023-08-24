#include "main.h"
/**
 * get_builtin - function that selects the right fonction
 *		to perform the command asked by the user.
 * @cmd: the user's command.
 * Return: a pointer to the right fonction.
 */
void (*get_builtin(char *cmd))(char **argv)
{
	builtin_fct options[] = {
		{"env", print_env},
		{"exit", exitbuiltin},
		{NULL, NULL}
	};

	int i = 0;

	while (options[i].str != NULL &&
			(_strncmp(options[i].str, cmd, _strlen(cmd))) != 0)
	{	i++; }
	return (options[i].f);
}
