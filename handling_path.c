#include "main.h"

char *real_path(char **buffer, int *faild)
{
	char *tok, *path, *brutforce;
	int found = 0, len;

	if (!buffer || !(*buffer))
		return (NULL);
	path = _getenvi();
	if (!path)
	{
		*faild = 1;
		return (*buffer);
	}
	tok = _strtok(path, ":");
	len = _strlen(*buffer);/*"ls/"*/
	while (tok)
	{
		brutforce = malloc(len + 2 + _strlen(tok));
		if (!brutforce)
		{
			free(path);
			return (*buffer);
			*faild = 1;
		}
		_strcpy(brutforce, tok);
		_strcat(brutforce, "/");
		_strcat(brutforce, *buffer);
		if (access(brutforce, X_OK) == 0)
			found = 1;
		if (found)
		{
			free(*buffer);
			free(path);
			return (brutforce);
		}
		free(brutforce);
		tok = _strtok(NULL, ":");
	}
	free(path);
	*faild = 1;
	return (*buffer);
}

char *_getenvi()
{
	char *tmp, *tok, *envvalue, *sdup, *envv;
	int i = 0;

	envv = "PATH";
	while (environ[i] != NULL)
	{
		tmp = _strdup(environ[i]);
		tok = _strtok(tmp, "=");

		if (_strcmp(tok, envv))
		{
			envvalue = _strtok(NULL, "\n");
			sdup = _strdup(envvalue);
			free(tmp);
			return (sdup);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

void print_env(void)
{
	size_t length;
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
