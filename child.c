#include "main.h"
/**
 * new_pro - Creates a new process to execute a command.
 * @s: Double pointer to the command and its arguments.
 * @buffer: Pointer to the input buffer.
 * @av: Command-line arguments.
 * @c: count.
 * Return: 0 on successful execution,
 *  127 on command not found,
 *  or exit status on error.
 */
int new_pro(char ***s, char **buffer, char *av, int c)
{
	pid_t child_p = 0;
	int status = 0, exit_s = 0, is = 0;

	if (c == 0)
		c = 1;
	child_p = fork();
	if (child_p)
		wait(&exit_s);
	else
	{
		if (access(*s[0], X_OK) == 0)
			execve(*s[0], *s, environ);
		else
		{
			is = berror(c, *buffer, av);
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
