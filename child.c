#include "main.h"


int new_pro(char ***s, char **buffer, char *av)
{
	pid_t child_p = 0;
	int status = 0, exit_s = 0, is = 0;

	child_p = fork();
	if (child_p)
		wait(&exit_s);
	else
	{
		if (access(*s[0], X_OK) == 0)
			execve(*s[0], *s, environ);
		else
		{
			is = berror(1, *buffer, av);
			if (is)
				return (0);
			else
				return (127);
		}
	}
	if (WIFEXITED(exit_s))
		status = WEXITSTATUS(exit_s);
	if (status != 0)
	{
		free_grid(*s), free(*buffer);
		return (status);
	}
	return (-1);
}