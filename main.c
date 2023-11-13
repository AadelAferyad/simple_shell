#include "main.h"

int main(int ac, char **av)
{
	int status = 0, p = 0, is = 0, exit_s = 0, get_line = 0, is_f = -1;
	pid_t child_p = 0;
	char **s = NULL, *buffer = NULL, *val = NULL, *value = NULL;
	struct stat st;
	size_t len = 0;

	if (isatty(STDIN_FILENO) != 0)
		return (interactive_mode(av[0]));
	while (1)
	{
		get_line = getline(&buffer, &len, stdin);
		if (get_line == -1)
		{
			free(buffer);
			write(0, "\n", 1);
			exit(0);
		}
		if (buffer[_strlen(buffer) - 1] == '\n')
			buffer[_strlen(buffer) - 1] = '\0';
		if (_strcmp(buffer, "exit"))
		{
			free(buffer);
			return (0);
		}
		if (_strcmp(buffer, "env"))
		{
			print_env();
			continue;
		}
		if (strncmp(buffer, "setenv", 6) == 0)
		{
			val = strtok(buffer + 7, " ");
			value = strtok(NULL, " ");
			_setenv(val, value);
			continue;
		}
		if (strncmp(buffer, "unsetenv", 8) == 0)
		{
			val = strtok(buffer + 9, " ");
			_unsetenv(val);
			continue;
		}
		if (!(s = allocate_argv_and_set(buffer, &is_f)))
		{
			if (is_f)
			{
				free(buffer);
				return (-1);
			}
			if (is_f == 0)
			{
				free(buffer); /*ne contineu here be careful*/
				return (0);
			}
		}
		if (stat(s[0], &st) == -1)
		{
			s[0] = real_path(&s[0], &p);
			if (p)
			{
				is = berror(1, buffer, av[0]);
				free_grid(s); /*if user input is not a valid cmd it should free then skip*/
				free(buffer);
				if (is)
					exit(0);
				else
					exit(127);
			}
		}
		child_p = fork();
		if (child_p)
			wait(&exit_s);
		else
		{
			if (access(s[0], X_OK) == 0)
				execve(s[0], s, environ);
			else
			{
				is = berror(1, buffer, av[0]);
				if (is)
					exit(0);
				else
					exit(127);
			}
		}
		if (WIFEXITED(exit_s))
			status = WEXITSTATUS(exit_s);
		if (status != 0)
		{
			free_grid(s);
			free(buffer);
			break;
		}
		free_grid(s);
	}
	return (status);
}
