#include "shell.h"

/**
 * split_line - tokenizes a string
 *
 * @str: string parameter (command from the terminal)
 * Return: Array of strings
 */
char **split_line(char *str)
{
	char **tokens, *token;
	int i = 0, j = 0;

	tokens = malloc(MAX_COMMANDS * sizeof(char *));
	if (tokens == NULL)
		perror("Can't allocate space\n"), exit(EXIT_FAILURE);

	/* to eliminate newline character */
	while (str[j])
	{
		if (str[j] == '\n')
			str[j] = '\0';
		j++;
	}
	/* then tokenize */
	token = strtok(str, " ");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL; /* to indicate end of array */
	return (tokens);
}
