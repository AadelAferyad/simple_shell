#include "main.h"


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

	if ((e = _strcmp_exit(*buffer)) > 0)
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