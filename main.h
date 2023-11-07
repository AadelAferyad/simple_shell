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

extern char **environ;

/*========================== Memory functions ============================*/
char *cut_the_first_word(char *buffer);
/*This function is used to cut the first word in the buffer string*/
/* the separator is space 32 for ex /bin/ls -l it should only take /bin/ls*/
char **allocate_argv_and_set(char *buffer);
/*This function is allocating enogh memory for ARGV to use in stat and execve*/
void free_grid(char **s);
/*free all the allocated momery for the words that user input buffer */
/*(char **s) s[0]=name of the cmd|s[1] =argmunts : ls -ll */
/*======================= End of memory functions ========================*/

/*============================ STR functions =============================*/
/* Write in STDERR FILENO (2)*/
void _puts(char *str);
void _putchar(char c);
void print_int(unsigned int n);
void berror(int count, char *buffer);
/*Print name of the cmd + count how many cmd + not found*/
int _strcmp(char *src, char *dest);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strtok(char *str, char *dahawmitr);
char *_strdup(char *str);
/*======================== End of STR functions ==========================*/

/*======================== Handling PATH functions ==========================*/
char *_getp(char *cmd);
char *_getenvi(char *envv);
/*======================== End of PATH functions ==========================*/

#endif
