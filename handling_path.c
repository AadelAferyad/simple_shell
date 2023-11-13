#include "main.h"
/**
 * real_path - Resolve the real path of a command in the system.
 * @buffer: The command to resolve.
 * @faild: A pointer to an integer indicating failure (1) or success (0).
 * Return: A dynamically allocated string with the resolved path, or the
 *         original buffer if the command is not found.
 */
char *real_path(char **buffer, int *faild)
{
	char *tok, *path, *brutforce;
	int found = 0, len;

	if (!buffer || !(*buffer))
		return (NULL);
	path = _getenvi();
	if (!path)
	{
		if (faild)
			*faild = 1;
		return (*buffer);
	}
	tok = _strtok(path, ":");
	len = _strlen(*buffer); /*"ls/"*/
	while (tok)
	{
		brutforce = malloc(len + 2 + _strlen(tok));
		if (!brutforce)
		{
			free(path);
			if (faild)
				*faild = 1;
			exit(EXIT_FAILURE);
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
	if (faild)
		*faild = 1;
	return (*buffer);
}

/**
 * _getenvi - Get the value of an environment variable.
 * Return: with the value of the environment variable
 *         or NULL if the variable is not found or has an empty value.
 */

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
			if (sdup[0] == '\0')
			{
				free(tmp);
				free(sdup);
				return (NULL);
			}
			free(tmp);
			return (sdup);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

/**
 * print_env - Print the environment variables to STDOUT.
 */
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
