#include "main.h"
/**
 * find_command - function that finds the full path of the input command
 *		in the envirement "PATH".
 * @command: the command passed by the user.
 * Return: the full path of the command if found, null if not.
 */
char *find_command(char *command)
{
	int i = 0, j = 1;
	char *path, *full_path;
	char **dir;
	struct stat st;

	if ( _strncmp(command, "exit", 4) == 0
			|| _strncmp(command, "env", 3) == 0)
		return (command);
	while (environ[i])
	{
		if (_strncmp(environ[i], "PATH", 4) == 0)
			break;
		i++; }
	if (environ[i] == NULL)
		return (NULL);
	path = malloc(_strlen(environ[i]) + 1);
	if (path == NULL)
	{	perror("hsh"), free(path);
		return (NULL); }
	_strcpy(path, environ[i]), dir = tokenize(path, ":=");
	full_path = malloc(MAX_SIZE + _strlen(command));
	if (full_path == NULL)
	{	perror("hsh"), free(path), free(dir);
		return (NULL); }
	if (_strncmp(command, "./", 2) == 0 || _strncmp(command, "../", 3) == 0
	|| _strncmp(command, "/", 1) == 0)
	{	_strcpy(full_path, command), free(path), free(dir);
		return (full_path); }
	while (dir[j + 1])
	{
		_strcpy(full_path, dir[j]), _strcat(full_path, "/");
		_strcat(full_path, command);
		if (stat(full_path, &st) == 0)
		{
			free(path), free(dir);
			return (full_path); }
		j++;
	}
	free(full_path), free(path), free(dir);
	return (NULL);
}
