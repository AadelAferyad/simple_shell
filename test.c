#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strlen(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }

    return i;
}

int main(void)
{
    char *buffer = NULL, *arguments[] = {NULL, NULL};
    int statusval;
    size_t len, buflength, childpr;
    ssize_t op;

    while (1)
    {
        write(1, "$ ", 2);
        op = getline(&buffer, &len, stdin);
        if (op == -1)
        {
            free(buffer);
            exit(0);
        }

        buflength = _strlen(buffer);
        if (op >= 0)
        {
            if (buffer[buflength - 1] == '\n')
            {
                buffer[buflength - 1] = '\0'; /* Replacing getline \n with \0 */
            }
            arguments[0] = buffer;
            childpr = fork();
            if (childpr == 0)
            {
                if (buffer[0] != '\0')
                {
                    if (execve(buffer, arguments, NULL) == -1)
                    {
                        fprintf(stderr, "Command '%s' not found\n", buffer);
                        exit(0);
                    }
                }
            }
            else if (childpr > 0)
            {
                wait(&statusval); /* delaying parent proccess until child proccess finish :( )*/
            }
            free(buffer);
            buffer = NULL;
        }
    }

    return 0;
}