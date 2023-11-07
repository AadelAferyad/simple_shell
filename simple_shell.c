#include "main.h"

int main(void)
{
	char *buffer = NULL, **s;
	size_t len = 0;
	int get_line, status, count = 0;
	pid_t child_p;
	struct stat st;

	while (1)
	{
		write(0, "#cisfun$ ", 9);
		get_line = getline(&buffer, &len, stdin);
		count++;
		if (get_line == -1)
		{
			free(buffer);
			write(0, "\n", 1);
			exit(0);
		}
		if (buffer[0] == '\n')
			continue;
		buffer[get_line - 1] = '\0';
		if (_strcmp(buffer, "exit"))
		{
			free(buffer);
			break;
		}
		s = allocate_argv_and_set(buffer);
		if (stat(s[0], &st) == -1)
		{
			s[0] = _getp(s[0]);
			if (stat(s[0], &st) == -1)
			{
				berror(count, buffer);
				free_grid(s);
				continue;
			}
		}
		child_p = fork();
		if (child_p)
			wait(&status);
		else if (child_p == 0)
		{
			if (execve(s[0], s, environ) == -1)
			{
				perror("execve");
				free(buffer);
				exit(2);
			}
		}
		free_grid(s);
	}
	return (0);
}