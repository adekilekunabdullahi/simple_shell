#include "main.h"
/**
 * path_check - a function that checks the path of a command
 * @str: path
 * Return: 1 on success 0r 0 on failure
 */
int path_check(char *str)
{
	char *cmp = "/bin/", *ptr, *path;
	int i = 0, j = 0;

	ptr = malloc(sizeof(char) * 55);
	if (ptr == NULL)
	{
		return (0);
	}
	while (cmp[i] != '\0')
	{
		if (cmp[i] != str[i])
		{
			free(ptr);
			return (0);
		}
		i++;
	}
	while (str[i] != '\0')
	{
		ptr[j] = str[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	path = create_path(ptr);
	if (path != NULL)
	{
		free(ptr);
		return (1);
	}
	return (0);
}
