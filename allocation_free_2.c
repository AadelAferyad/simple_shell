#include "main.h"



int count_words_echo(char *buffer)
{
	int i = 0, words = 0;

	if (buffer[0] != 32)
		words++;
	while (buffer[i])/*"echo "   " "*/
		{
			if (buffer[i] == 34)
			{
				i++;
				while (buffer[i] != 34)
						i++;
			}
			if (buffer[i] == 32 && buffer[i + 1] != 32 && buffer[i + 1])
				words++;
			i++;
		}
		return (words);
}


char *alloc_words_echo(char *buffer, int *index_buffer)
{
	char *s;
	int i = 1, j = 0;

	while (buffer[i] != 34 && buffer[i])/*"echo "    " "*/
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	*index_buffer = *index_buffer + i;
	while (j < i)
	{
		s[j] = buffer[j];
		j++;
	}
	s[j] = '\0';
	return (s);
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
	for (;i < len; i++)
		new[i] = buffer[i];
	new[i] = '\0';
	return (new);
}

int is_path()
{
	int i = 0;
	char *tmp, *path;

	path = _getenvi();
	if (!path)
		return (0);
    tmp = strtok(path, ":");
	while (path[i])
	{
        if (_strcmp(tmp, "/usr/bin"))
		{
			free(path);
            return (1);
		}
		tmp = strtok(NULL, ":");
        i++;
    }
	free(path);
    return (0);
}
char *real_path(char **buffer)
{
	char *tok, *path, *brutforce;
	int found = 0, len;
	struct stat tv;

	path = _getenvi();
	if (!path || !buffer || !(*buffer))
		return (NULL);
	tok = strtok(path, ":");
	len = _strlen(*buffer);
	while (tok)
	{
		brutforce = malloc(len + 2 + _strlen(tok));
		if (!brutforce)
			return (NULL);
		strcpy(brutforce, tok);
		strcat(brutforce, "/");
		strcat(brutforce, *buffer);
		if (stat(brutforce, &tv) != -1)
			found = 1;
		if (found)
		{
			free(*buffer);
			free(path);
			return (brutforce);
		}
		free(brutforce);
		tok = strtok(NULL, ":");
	}
	free(path);
	free(*buffer);
	return (NULL);
}

char *_getenvi()
{
    char *tmp, *tok, *envvalue, *sdup, *envv;
    int i = 0;

	envv = "PATH";
    while (environ[i] != NULL)
    {
        tmp = _strdup(environ[i]);
        tok = strtok(tmp, "=");

        if (_strcmp(tok, envv))
        {
            envvalue = strtok(NULL, "\n");
            sdup = _strdup(envvalue);
            free(tmp);
            return (sdup);
        }
        free(tmp);
        tmp = NULL;
        i++;
    }
    return (NULL);
}

char *concat_bin(char **buffer)
{
	int len, i;
	char *n;

	if (!buffer || !(*buffer))
		return (NULL);
	len = _strlen(*buffer);
	n = malloc(len + 6);
	if (!n)
		return (NULL);
	n[0] = '/', n[1] = 'b';
	n[2] = 'i', n[3] = 'n';
	n[4] = '/';

	for (i = 0; i < len; i++)
		n[i + 5] = (*buffer)[i];
	n[i + 5] = '\0';
	free(*buffer);
	return (n);
}