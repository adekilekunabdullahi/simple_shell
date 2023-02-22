#include "main.h"
/**
 * create_path - a function that create a path if it doesnt exist.
 * @string: name of the alias file
 * Return: return concat path name
 */
char *create_path(char *string)
{
	DIR *dir = opendir("/bin/");
	char *name, *new_path;
	struct dirent *direct;

	if (dir == NULL)
		return (NULL);
	direct = readdir(dir);
	while (direct != NULL)
	{
		name = direct->d_name;
		if (_strcmp(name, string) == 0)
		{
			new_path = strcat("/bin/", string);
			closedir(dir);
			return (new_path);
		}
		direct = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
