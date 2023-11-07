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
int count_words_echo(char *buffer);
char *alloc_words_echo(char *buffer, int *index_buffer);
int count_words(char *buffer);
char *alloc_words_buffer(char *buffer, int *index_buffer);
char **allocate_argv_and_set(char *buffer);
void free_grid(char **s);

char *cut_the_first_word(char *buffer);


/*======================= End of memory functions ========================*/

/*============================ STR functions =============================*/
void berror(int count, char *buffer);
char *skip_space_tab_for_berror(char *buffer);
int _strcmp(char *src, char *dest);
int _strcmp_echo(char *dest);
char *_strdup(char *buffer);
int _strlen(char *str);
void print_int(unsigned int n);
void _putchar(char c);
void _puts(char *str);
/*======================== End of STR functions ==========================*/

/*============================ path functions =============================*/
char *real_path(char **buffer);
char *_getenvi();
/*======================== End of path functions ==========================*/


#endif
