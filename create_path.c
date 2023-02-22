#include "shell.h"

/**
 * create_path - check if command exists and then
 * constructs a path to the command.
 *
 * @str: string to apply the check
 * Return: path to command or NULL if command is not found
 */
char *create_path(char *str)
{
	DIR *dir = opendir("/bin/");
	char *temp, *path;
	struct dirent *file;

	if (!dir)
		return (NULL);
	file = readdir(dir);
	while (file)
	{
		temp = file->d_name;
		if (_strcmp(temp, str) == 0)
		{
			path = _strcat("/bin/", str); /* construct command path */
			closedir(dir);
			return (path);
		}
		file = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
