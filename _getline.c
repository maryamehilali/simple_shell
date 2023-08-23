#include "main.h"
/**
 * _getline - duplicate of the getline function that reads a line from stdin.
 * @buffer: the buffer to store the input.
 * @bufsize: size of the buffer.
 * Return: number of chars read on success, -1 on fail.
 */

int  _getline(char **buffer, size_t *bufsize)
{
	/*ssize_t bufsize = 2;*/
	char c = 0;
	ssize_t char_read;
	size_t i;

	(*buffer) = malloc(*bufsize);
	if ((*buffer) == NULL)
		return (-1);
	for (i = 0; (char_read = read(STDIN_FILENO, &c, 1)) > 0 && c != '\n'; i++)
	{
		if (i + 1 >= (*bufsize))
		{
			(*bufsize) = (*bufsize) + 10;
			(*buffer) = realloc((*buffer), (*bufsize));
			if ((*buffer) == NULL)
				return (-1); }
		(*buffer)[i] = c;
	}
	if (char_read == 0 && i == 0)
	{	free((*buffer));
		(*buffer) = NULL; }

	return (i);
}
