#include "main.h"
/**
 *read_line - function that reads and parse arguments vectors.
 *@string: line to parse
 *Return: pointer to char pointer.
 */
char **read_line(char *string)
{
	int length = 0, i = 0;
	char *token;
	char **tokens;
	char *delimiters = " ";

	tokens = malloc(sizeof(char *) * MAX_COMMANDS);
	if (!tokens)
		perror("Error: can't allocate space\n"), exit(1);
	while (string[i])
	{
		if (string[i] == '\n')
		{
			string[i] = '\0';
		}
		i++;
	}
	token = strtok(string, delimiters);
	while (token != NULL)
	{
		tokens[length] = token;
		length++;
		token = strtok(NULL, delimiters);
	}
	tokens[i] = NULL;
	/*free(string);*/
	return (tokens);
}
/**
 * _strlen - a function that returns the length of a string
 * @s: string
 * Return: length of a string
 */
int _strlen(char *s)
{
	int i;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
#include <stdio.h>
#include "main.h"
#include <string.h>
/**
 * _strcpy - a function that  copies the string pointed to by src
 * including the terminating null byte (\0), to the buffer pointed to by dest.
 * @dest: a parameter to copy to.
 * @src: a parameter to copy from
 * Return: character copied.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
