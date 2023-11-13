#include "main.h"
/**
 * redirector - Redirects input based on the provided buffer content.
 * @buffer: Double pointer to the input buffer.
 * @get_line: Flag indicating if a new line is obtained.
 * @av: Command-line arguments.
 * Return: 0 if get_line is -1, 1 if buffer contains only '\n',
 *         -1 on error.
 */
int redirector(char **buffer, int get_line, char *av)
{
	int e = 0, exit_s = 0;

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
			exit_s = berror_exit(1, *buffer + 5, av);
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
 *
 * Return: 0 if the file path does not exist,
 *  -1 on successful path, 127 on error.
 */
int path_faild(char **buffer, char ***s, char *av)
{
	int is = 0, p = 0;
	struct stat st;

	if (stat(*s[0], &st) == -1)
	{
		*s[0] = real_path(&(*s[0]), &p);
		if (p)
		{
			is = berror(1, *buffer, av), free_grid(*s), free(*buffer);
			if (is)
				return (0);
			else
				return (127);
		}
	}
	return (-1);
}