#include "main.h"
/**
 * main - a littele version of shell that execute the appropriate
 *		program depending on the command given by the user.
 * Return: always 0.
 */
int main(void)
{
	char **command_parts;
	char *command, *input;
	pid_t child_pid;
	int status;

	for (;;)
	{
		errno = 0;
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		input = user_input(), command_parts = tokenize(input, " \t\n");
		if (command_parts == NULL || command_parts[0] == NULL)
		{	free(input), free(command_parts);
			continue; }
		command = find_command(command_parts[0]);
		if (command != NULL)
		{
			if (_strncmp(command_parts[0], "exit", 5) == 0)
			{
				free(input), free(command_parts);
				exit(0); }
			else if (_strncmp(command_parts[0], "env", 3) == 0)
				print_env();
			else
			{	child_pid = fork();
				if (child_pid == -1)
				{	perror("./hsh"), exit(errno); }
			else if (child_pid == 0)
			{
				if (execve(command, command_parts, environ) == -1)
				{	perror("./hsh");
					exit(errno); }}
			else
			{	wait(&status), errno = WIFEXITED(status);
				free(input), free(command_parts); }}}
		else
		{	perror("./hsh"), free(input), free(command_parts); }}
	return (0); }
