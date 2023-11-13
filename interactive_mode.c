#include "main.h"

int interactive_mode(char *av)
{
	char *buffer = NULL, **s = NULL, *val = NULL, *value = NULL;
	size_t len = 0;
	int get_line, status = 0, count = 0, is, status_exit = 0;
	pid_t child_p = 0;
	struct stat st;

	while (1)
	{
		write(STDOUT_FILENO, "#camel$ ", 8);
		is = 0;
		get_line = getline(&buffer, &len, stdin); /*Buffer allocated*/
		count++;
		if (get_line == -1)
		{
			free(buffer);
			write(0, "\n", 1);
			return (0);
		}
		if (buffer[0] == '\n')
			continue;
		if (buffer[get_line - 1] == '\n')
			buffer[get_line - 1] = '\0';
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
		if (!(s = allocate_argv_and_set(buffer, NULL)))
		{
			free(buffer);
			break;
		}
		if (stat(s[0], &st) == -1)
		{
			s[0] = real_path(&s[0], &is);
			if (is)
			{
				berror(count, buffer, av);
				free_grid(s); /*if user input is not a valid cmd it should free then skip*/
				continue;
			}
		}
		child_p = fork();
		if (child_p)
			wait(&status_exit);
		else if (child_p == 0)
		{
			if (execve(s[0], s, environ) == -1)
			{
				/*printf("wa lbhlawan\n");*/
				free(buffer);
				return (2);
			}
		}
		if (WIFEXITED(status_exit))
			status = WEXITSTATUS(status_exit);
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