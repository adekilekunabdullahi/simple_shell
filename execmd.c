#include "main.h"
/**
 * execmd - fuction that execute a command
 * @tokens: array of strings
 * @argv: arguments vector
 * @env: environments vector
 */
void execmd(char **tokens, char **argv, char **env)
{
	int status;
	char *cmd = NULL;
	pid_t child;

	cmd = tokens[0];
	child = fork();
	if (child < 0)
	{
		perror("Error");
		return;
	}
	if (child == 0)
	{
		if (execve(cmd, tokens, env) == -1)
		{
			_printf("%s: No such file or directory\n", argv[0]);
		}
	}
	else
		wait(&status);
}
