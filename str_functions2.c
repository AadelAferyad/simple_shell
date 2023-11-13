#include "main.h"
/**
 * _strlen - count length of string
 * @str: pointer to char
 * Return: return the length
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _strcmp - compare two strings
 * @src: first string
 * @dest: second string
 * Return: comparaison result
 */
int _strcmp(char *src, char *dest)
{
	int i = 0;

	if (!src || !dest)
		return (0);
	for (; src[i] && dest[i]; i++)
	{
		if (src[i] != dest[i])
			return (0);
	}
	return ((src[i] == dest[i]) ? 1 : 0);
}
/**
 * _strcmp_echo - Compare a string with the "echo" command.
 * @dest: The string to compare with the "echo" command.
 * @src: The string.
 * Return: 1 if @dest is equal to "echo", 0 otherwise.
 */
int _strcmp_echo(char *dest, char *src)
{
	int i = 0, j = 0;

	if (!src) /*"env env, exittt"*/
		src = "echo";
	for (; src[i]; i++)
	{
		if (src[i] != dest[i])
			return (0);
	}
	if (dest[i] != '\0')
	{
		j = i;
		while (dest[j])
		{
			if (src[i] == '\0' && (dest[j] == 32 || dest[j] == 9))
				j++;
			else
				return (0);
		}
	}
	return (1);
}
/**
 * _strdup - function that allocates a block of memory and initialize it.
 * @buffer: string will be coppied to the allocated memory.
 * Return: return allocated memory.
 */
char *_strdup(char *buffer)
{
	char *new;
	int i = 0, len;

	if (!buffer)
		return (NULL);
	len = _strlen(buffer);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	for (; i < len; i++)
		new[i] = buffer[i];
	new[i] = '\0';
	return (new);
}
/**
 * _strtok - Tokenize a string using specified delimiters.
 * @str: The string to tokenize.
 * @dahawmitr: The delimiters used for tokenization.
 * Return: pointer to the next token or NULL if no more tokens are found.
 */
char *_strtok(char *str, char *dahawmitr)
{
	static char *buffer;
	char *token, *agadir;

	if (str != NULL)
	{
		buffer = str;
	}
	if (buffer == NULL)
	{
		return (NULL);
	}
	while (*buffer != '\0' && _strchr(dahawmitr, *buffer) != NULL)
	{
		buffer++;
	}
	token = buffer;
	agadir = buffer;
	while (*agadir != '\0')
	{
		if (_strchr(dahawmitr, *agadir) != NULL)
		{
			*agadir = '\0';
			buffer = agadir + 1;
			return (token);
		}
		agadir++;
	}
	buffer = NULL;
	return (token);
}
