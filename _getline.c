#include "shell.h"

/**
 * _getline - Print "$ " first with the string after it on next line
 * @linePtr: parameter of address holding buffer of string
 * @n: length of string
 *@stream: The stream to receive file;
 * Return: length of input string
 */
ssize_t _getline(char **linePtr, size_t *n, FILE *stream)
{
	char str[120];

	if (linePtr == NULL || n == NULL || stream == NULL)
	{
		perror("Error! wrong parameter or file pointer problem");
		exit(1);
	}
	if (*linePtr == NULL)
	{
		*linePtr = malloc(sizeof(str));
		if (*linePtr == NULL)
		{
			perror("Unable to allocate memory");
			exit(1);
		}
	}
	*linePtr[0] = '\0';
	while (fgets(*linePtr, *n, stream))
	{
		if ((*n - strlen(*linePtr)) < sizeof(str))
		{
			*n *= 2;
			*linePtr = realloc(*linePtr, *n);
			if (*linePtr == NULL)
			{
				perror("Unable to reallocate memory");
				exit(1);
			}
		}
		strcat(*linePtr, str);
		if ((*linePtr)[strlen(*linePtr) - 1] == '\n')
			return (strlen(*linePtr));
	}
	return (0);
}
