#include "main.h"
/**
 * redirector - Redirects input based on the provided buffer content.
 * @buffer: Double pointer to the input buffer.
 * @get_line: Flag indicating if a new line is obtained.
 * @av: Command-line arguments.
 * @c: count.
 * @i: for interactive mode should i free or not.
 * Return: 0 if get_line is -1, 1 if buffer contains only '\n',
 * -1 on error.
 */
int redirector(char **buffer, int get_line, char *av, int c, int i)
{
	int e = 0, exit_s = 0;

	if (c == 0)
		c = 1;
	if (get_line == -1)
	{
		free(*buffer), write(0, "\n", 1);
		return (0);
	}
	if (*buffer[0] == '\n')
		return (1);
	if (buffer[0][_strlen(*buffer) - 1] == '\n')
		buffer[0][_strlen(*buffer) - 1] = '\0';
	if (_strcmp_echo(*buffer, "env"))
	{
		print_env();
		return (1);
	}
	e = _strcmp_exit(*buffer);
	if (e > 0)
	{
		if (e == 2)
			exit_s = advnce_exit(*buffer, av);
		if (e == 3)
			exit_s = berror_exit(c, *buffer + 5, av);
		if (i)
			free(*buffer);
		return (exit_s);
	}
	return (-1);
}
/**
 * allocat_faild - Handles memory allocation failure.
 * @s: Double pointer to a string.
 * @buffer: Pointer to the input buffer.
 * @is_f: Integer flag indicating the type of failure.
 * Return: -1 on allocation failure, 0 on normal failure,
 *  2 on successful allocation.
 */
int allocat_faild(char ***s, char **buffer, int is_f)
{

	if (!(*s))
	{
		if (is_f)
		{
			free(*buffer);
			return (-1);
		}
		if (is_f == 0)
		{
			free(*buffer); /*ne contineu here be careful*/
			return (0);
		}
	}
	return (2);
}
/**
 * path_faild - Handles failure related to the file path.
 * @buffer: Pointer to the input buffer.
 * @s: Double pointer to a string.
 * @av: Command-line arguments.
 * @c: count.
 * @i: for interactive mode should i free or not.
 * Return: 0 if the file path does not exist,
 *  -1 on successful path, 127 on error.
 */
int path_faild(char **buffer, char ***s, char *av, int c, int i)
{
	int is = 0, p = 0;
	struct stat st;

	if (c == 0)
		c = 1;
	if (stat(*s[0], &st) == -1)
	{
		*s[0] = real_path(&(*s[0]), &p);
		if (p)
		{
			is = berror(c, *buffer, av), free_grid(*s);
			if (i)
				free(*buffer);
			if (is)
				return (0);
			else
				return (127);
		}
	}
	return (-1);
}

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
