#include "main.h"



int main(void)
{
	char *buffer = NULL, **s, *env[]={"HOME=/home/user", "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin", NULL};
	size_t len = 0;
	int get_line, status, count = 0;
	pid_t child_p;
	struct stat st;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		get_line = getline(&buffer, &len, stdin);
		count++;
		if (get_line == -1)
		{
			free(buffer);
			write(1, "\n", 1);
			exit(EXIT_FAILURE);
		}
		if (buffer[0] == '\n')
			continue;
		buffer[get_line - 1] = '\0';
		s = allocate_argv_and_set(buffer);
		if (stat(s[0], &st) == -1)
		{
			printf("#cisfun$: %d: %s: not found\n", count, buffer);
			continue;
		}
		child_p = fork();
		if (child_p)
			wait(&status);
		else if (child_p == 0)
		{

			if (execve(s[0], s, env) == -1)
			{
				
				/*perror(buffer);*/
				/*printf("#cisfun$: %d: %s: not found\n", count, buffer);*/
				printf("wa lbhlawan\n");
				free(buffer);
				exit(2);
			}
		}
		free_grid(s);
	}
	return (0);
}