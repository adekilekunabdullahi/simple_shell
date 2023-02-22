#include "shell.h"

/**
 * main - Entry point for shell program
 * @argc: number of arguments
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	char **tokens;
	size_t n = 0, imbt, status;
	ssize_t num_char;
	char *line = NULL, *path, *error_message;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		/* for interactive mode only */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		/* fetch user's command from terminal */
		num_char = getline(&line, &n, stdin);
		if (num_char == -1)
			free(line), exit(EXIT_FAILURE);

		if (*line != '\n')
		{
			tokens = split_line(line);
			imbt = match_builtin(tokens);
			error_message = _strcat(tokens[0], ": command not found\n");
			/* for commands without path */
			path = create_path(tokens[0]);
			if (path)
				tokens[0] = path;
			/* for commands with path */
			else
				status = path_check(tokens[0]);
			if (status == 1 || path)
				exec_command(tokens, argv, envp);
			if (status != 1 && !path && imbt == 0)
				write(STDERR_FILENO, error_message, _strlen(error_message));
		}
	}
	free(tokens);
	free(line);
	exit(0);
}
