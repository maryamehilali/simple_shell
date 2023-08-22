#include "main.h"

/**
 * free_commands_array - frees the array char ** containing strings.
 * @array:array to free.
 * Return: nothing
 */

void free_commands_array(char **array)
{
	int i;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
}
