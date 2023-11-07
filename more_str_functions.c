#include "main.h"

int _strcmp(char *src, char *dest) /* "exit" exit*/
{
	int i = 0;

	for (; src[i] && dest[i]; i++)
	{
		if (src[i] != dest[i])
			return (0);
	}
	return ((src[i] == dest[i]) ? 1 : 0);
}
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	if (s[i] == c)
		return (&s[i]);

	return (NULL);
}
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	for (; dest[i] != '\0'; i++)
	{
		continue;
	}

	for (; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
char *_strcpy(char *dest, char *src)
{
	char *destStart = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (destStart);
}

char *_strdup(char *str)
{
	int i, len;
	char *s;

	if (str == 0)
	{
		return (NULL);
	}

	len = _strlen(str);
	s = malloc(len + 1 * sizeof(char));

	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		s[i] = str[i];
	}
	s[i] = '\0';
	return (s);
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
