#include "main.h"
int _myexit()
{
	return (0);
}
int _myenv()
{
	extern char **environ;
	int i = 0;
	for (i = 0; environ[i] != 0; i++)
		_printf("%s\n", environ[i]);
	return (0);
}

void check_for_alias(char *tokens)
{
	int counter = 0;
	builtin my_builtin[] =
	{
		{"exit", _myexit},
		{"env", _myenv},
	};
	while (my_builtin[counter].name != NULL)
	{
		if (strcmp(tokens, my_builtin[counter].name) == 0)
			my_builtin[counter].func();
		counter++;
	}
}
