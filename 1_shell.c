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
	void (*fonct)(char **);

	for (;;)
	{
		errno = 0;
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		input = user_input(), command_parts = tokenize(input, " \t\n");
		if (!command_parts || !command_parts[0])
		{	free(input), free(command_parts);
			continue; }
		command = find_command(command_parts[0]);
		fonct = get_builtin(command_parts[0]);
		if (fonct)
		{
			free(input);
			fonct(command_parts);
			free(command_parts);
		}
		else if (command)
		{
			execute(command, command_parts);
			free(input), free(command_parts), free(command);
		}
		else
		{	perror("./hsh"), free(command), free(input), free(command_parts); }
	}
	return (0);
}

/**
 * execute - function that fork a child and execute the command.
 * @cmd: the full path of the command.
 * @argv: command parts gotten from user.
 */
void execute(char *cmd, char **argv)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{	perror("./hsh"), exit(EXIT_FAILURE); }
	else if (child_pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{	perror("./hsh"), exit(EXIT_FAILURE); }
	}
	else
		wait(&status);
}
/**
 * exitbuiltin - function that exit the shell with a status.
 * @argv: command and status gotten from user.
 */
void exitbuiltin(char **argv)
{
	int exit_status;

	if (argv[1])
	{
		exit_status = _atoi(argv[1]);
		free(argv);
		exit(exit_status);
	}
		free(argv);
		exit(EXIT_SUCCESS);
}

