#include "main.h"

int _setenv(char *var, char *value)
{
    int i = 0, envlen = 0;
    char *newkey = NULL, **newenviron = NULL;

    if (!var || !value)
    {
        return (-1);
    }
    while (environ[envlen] != NULL)
    {
        envlen++;
    }
    newenviron = malloc(sizeof(char *) * (envlen + 2));
    if (newenviron == NULL)
    {
        return (-1);
    }
    for (; environ[i] != NULL; i++)
    {
        if (_strcmp(environ[i], var) == 0)
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