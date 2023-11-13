#include "main.h"
/**
 * _setenv - Set or update an environment variable.
 * @var: The name of the environment variable to set or update.
 * @value: The value to assign to the environment variable.
 * Return: 0 on success, -1 on failure.
 */
int _setenv(char *var, char *value)
{
	int i = 0, envlen = 0;
	char *newkey = NULL, **newenviron = NULL;

	if (!var || !value)
		return (-1);
	while (environ[envlen] != NULL)
		envlen++;
	newenviron = malloc(sizeof(char *) * (envlen + 2));
	if (newenviron == NULL)
		return (-1);
	for (; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], var, strlen(var)) == 0)
		{
			newkey = malloc(_strlen(var) + _strlen(value) + 2);
			if (newkey == NULL)
			{
				free(newenviron);
				return (-1);
			}
			free(environ[i]);
			_strcpy(newkey, var);
			_strcat(newkey, "=");
			_strcat(newkey, value);
			newenviron[i] = newkey;
			return (0);
		}
		newenviron[i] = environ[i];
	}
	newkey = malloc(_strlen(var) + _strlen(value) + 2);
	if (newkey == NULL)
	{
		free(newenviron);
		return (-1);
	}
	_strcpy(newkey, var);
	_strcat(newkey, "=");
	_strcat(newkey, value);
	newenviron[i] = newkey;
	newenviron[i + 1] = NULL;
	free(environ);
	environ = newenviron;
	return (0);
}
/**
 * _unsetenv - Remove an environment variable.
 * @name: The name of the environment variable to remove.
 * Return: 0 on success, -1 if the variable is not found.
 */
int _unsetenv(char *name)
{
	int i, j, len;

	if (!name)
		return (-1);
	len = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, len) == 0)
		{
			for (j = i; environ[j + 1] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			environ[j] = NULL;
			return (0);
		}
	}
	return (-1);
}
