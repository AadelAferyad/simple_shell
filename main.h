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


/*========================== Memory functions ============================*/
char *cut_the_first_word(char *buffer);
/*This function is used to cut the first word in the buffer string*/
/* the separator is space 32 for ex /bin/ls -l it should only take /bin/ls*/
char **allocate_argv_and_set(char *buffer);
/*This function is allocating enogh memory for ARGV to use in stat and execve*/
char *concat_bin(char **buffer);
/*concatenate bin with the user input cmd ("/bin/" + "clear")*/
void free_grid(char **s);
/*free all the allocated momery for the words that user input buffer */
/*(char **s) s[0]=name of the cmd|s[1] =argmunts : ls -ll */
/*======================= End of memory functions ========================*/

/*============================ STR functions =============================*/
void _putchar(char c);
/* Write in STDERR FILENO (2)*/
void _puts(char *str);
void print_int(unsigned int n);
int _strlen(char *str);
void berror(int count, char *buffer);
/*Print name of the cmd + count how many cmd + not found*/
int _strcmp(char *src, char *dest);
/*======================== End of STR functions ==========================*/

#endif
