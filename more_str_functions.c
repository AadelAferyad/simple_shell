#include "main.h"

int _strcmp(char *src, char *dest) /* "exit" exit*/
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

int _strcmp_echo(char *dest)
{
	int i = 0;
	char *s = "echo";
	for (; s[i] && dest[i]; i++)
	{
		if (s[i] != dest[i])
			return (0);
	}
	return ((s[i] == '\0') ? 1 : 0);
}

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
