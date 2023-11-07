#include "main.h"

char *_getenvi(char *envv)
{
    char *temporary, *agadir, *envvalue, *environement;
    int i = 0;

    while (environ[i] != NULL)
    {
        temporary = _strdup(environ[i]);
        agadir = _strtok(temporary, "=");

        if (_strcmp(agadir, envv))
        {
            envvalue = _strtok(NULL, "\n");
            environement = _strdup(envvalue);
            free(temporary);
            return environement;
        }
        free(temporary);
        temporary = NULL;
        i++;
    }
    return NULL;
}

char *_getp(char *cmd)
{
    char *path_env, *full_cmd, *directory;
    int i = 0;
    struct stat st;

    for (; cmd[i] != '\0'; i++)
    {
        if (cmd[i] == '/')
        {
            if (stat(cmd, &st) == 0)
            {
                return (_strdup(cmd));
            }
            return (NULL);
        }
    }

    path_env = _getenvi("PATH");
    directory = _strtok(path_env, ":");
    while (directory != NULL)
    {
        full_cmd = malloc(_strlen(directory) + _strlen(cmd) + 2);
        if (full_cmd != NULL)
        {
            _strcpy(full_cmd, directory);
            _strcat(full_cmd, "/");
            _strcat(full_cmd, cmd);
            if (stat(full_cmd, &st) == 0)
            {
                free(path_env);
                return (full_cmd);
            }
            free(full_cmd);
            full_cmd = NULL;
            directory = _strtok(NULL, ":");
        }
    }
    free(path_env);
    return (NULL);
}
