#include "main.h"
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
