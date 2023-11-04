#ifndef _SHELL_
#define _SHELL_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>


char *cut_the_first_word(char *buffer);
/*This function is used to cut the first word in the buffer string
  the separator is space 32 for ex /bin/ls -l it should only take /bin/ls
*/

int _strlen(char *str);
char **allocate_argv_and_set(char *buffer);
/*
  This function is allocating enogh memory for ARGV to use in stat and
  execve functions
*/
void free_grid(char **s);

#endif