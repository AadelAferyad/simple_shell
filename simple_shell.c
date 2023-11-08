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
		get_line = getline(&buffer, &len, stdin); /*Buffer allocated*/
		count++;
		if (get_line == -1)
		{
			free(buffer);
			write(0, "\n", 1);
			exit(0);
		}
		if (buffer[0] == '\n')
			continue;
		if (buffer[get_line - 1] == '\n')
			buffer[get_line - 1] = '\0';
		if (_strcmp(buffer, "exit"))
		{
			free(buffer);
			break;
		}
		if (!(s = allocate_argv_and_set(buffer)))
		{
			free(buffer);
			break;
		}
		if (stat(s[0], &st) == -1)
		{
			s[0] = real_path(&s[0]);
			if (s[0] == NULL)
			{
				free_grid(s); /*if user input is not a valid cmd it should free then skip*/
				berror(count, buffer);
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
				/*printf("wa lbhlawan\n");*/
				free(buffer);
				exit(2);
			}
		}
		free_grid(s);
	}
	return (0);
}