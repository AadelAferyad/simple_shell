#include "main.h"
/**
 * interactive_mode - A basic interactive shell.
 * @av: Command-line arguments.
 * Return: 0 or exit failure.
 */
int interactive_mode(char *av)
{
	char *buffer = NULL, **s = NULL;
	size_t len = 0;
	int get_line, status = 0, count = 0, is, exit_s = 0, is_f = 0;

	while (1)
	{
		write(STDOUT_FILENO, "#marvel$ ", 9), is = 0;
		get_line = getline(&buffer, &len, stdin);
		count++;
		exit_s = redirector(&buffer, get_line, av, count, 0);
		if (exit_s == 1 || exit_s == 2)
			continue;
		else if (exit_s != -1)
			return (exit_s);
		s = allocate_argv_and_set(buffer, &is_f);
		exit_s = allocat_faild(&s, &buffer, is_f);
		if (exit_s != 2)
			return (exit_s);
		is = path_faild(&buffer, &s, av, count, 0);
		if (is != -1)
		{
			continue;
		}
		status = new_pro(&s, &buffer, av, count);
		if (status != -1)
			continue;
		free_grid(s);
	}
	return (status);
}
