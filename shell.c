#include "main.h"
/**
 * main - simple shell main function
 * @argc: argument counts
 * @argv: arguments vector
 * @env: enviroments parameter
 * Return: success
 */
int main(int argc, char **argv, char **env)
{
	char **tokens, *text = NULL, *path;
	int num, i = 0;
	ssize_t j;
	size_t n = 0, y;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		num = isatty(STDIN_FILENO);
		if (num == 1)
			_printf("#cisfun$ ");
		j = getline(&text, &n, stdin);
		if (j == -1)
		{
			free(text);
			exit(1);
		}
		if (*text != '\n')
		{
			tokens = read_line(text);
			if (_strcmp("exit", tokens[0]) == 0)
			{
				free(text);
				break;
			}
			else if (_strcmp("env", tokens[0]) == 0)
			{
				for (i = 0; env[i] != 0; i++)
				{
					_printf("%s\n", env[i]);
				}
			}
			else
			{
				path = create_path(tokens[0]);
				if (path)
					tokens[0] = path;
				else
					y = path_check(tokens[0]);
				if (y == 1 || path)
					execmd(tokens, argv, env);
				if (y != 1 && !path)
					_printf("%s: command not found\n", argv[0]);
			}
		}
		free(text);
		free(tokens);
	}
	return (0);
}
