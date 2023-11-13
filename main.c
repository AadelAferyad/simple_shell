#include "main.h"

int main(int ac, char **av)
{
	int status = 0, is = 0, exit_s = 0, get_line = 0, is_f = -1;

	char **s = NULL, *buffer = NULL;
	size_t len = 0;

	if (isatty(STDIN_FILENO) != 0)
		return (interactive_mode(av[0]));
	while (1)
	{
		get_line = getline(&buffer, &len, stdin);
		exit_s = redirector(&buffer, get_line, av[0]);
		if (exit_s == 1)
			continue;
		else if (exit_s != -1)
			return (exit_s);
		s = allocate_argv_and_set(buffer, &is_f);
		exit_s = allocat_faild(&s, &buffer, is_f);
		if (exit_s != 2)
			return (exit_s);
		is = path_faild(&buffer, &s, av[0]);
		if (is != -1)
			return (is);
		status = new_pro(&s, &buffer, av[0]);
		if (status != -1)
			return (status);
		free_grid(s);
	}
	return (0);
}
