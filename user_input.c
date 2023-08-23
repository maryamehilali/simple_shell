#include "main.h"

/**
 * tokenize - function that takes a single string and split it into
 *		an array of strings using the delimeter delim.
 * @string: the input string.
 * @delim: the chosen delimeter.
 * Return: An array containing the result strings.
 */

char **tokenize(char *string, char *delim)
{
	char *token;
	char **words;
	int i = 0;

	words = malloc(sizeof(char *) * MAX_SIZE);
	if (words == NULL)
	{
		perror("hsh");
		return (NULL);
	}
	token = strtok(string, delim);
	while (token)
	{
		words[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	words[i] = NULL;
	return (words);
}
/**
 * user_input - fonction that readsthe user input form the stdin
 *		and split it into command and arguments.
 * Return: array of differents parts of the command entered by the user.
 **/

char *user_input(void)
{
	int char_read;
	char *buffer = NULL;
	size_t buf_size = sizeof(char) * MAX_SIZE;

	char_read = getline(&buffer, &buf_size, stdin);
	/*char_read = _getline(&buffer, &buf_size);*/
	if (char_read < 0)
	{
		free(buffer);
		write(0, "\n", 1);
		exit(0);
	}
	if (buffer[char_read - 1] == '\n')
		buffer[char_read - 1] = '\0';
	return (buffer);
}
