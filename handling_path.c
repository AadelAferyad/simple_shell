#include "main.h"



char *real_path(char **buffer)
{
	char *tok, *path, *brutforce;
	int found = 0, len;
	struct stat tv;

	if (!buffer || !(*buffer))
		return (NULL);
	path = _getenvi();
	if (!path)
		return (NULL);
	tok = strtok(path, ":");
	len = _strlen(*buffer);
	while (tok)
	{
		brutforce = malloc(len + 2 + _strlen(tok));
		if (!brutforce)
		{
			free(path);
			return (NULL);
		}
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
        i++;
    }
    return (NULL);
}
