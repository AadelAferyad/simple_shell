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
int count_words(char *buffer);
int count_words_echo(char *buffer);
char *alloc_words_echo(char *buffer, int *index_buffer);
char *alloc_words_buffer(char *buffer, int *index_buffer);
char **allocate_argv_and_set(char *buffer, int *f);
char *cut_the_first_word(char *buffer);
void free_grid(char **s);
/*======================= End of memory functions ========================*/
int redirector(char **buffer, int get_line, char *av);
int allocat_faild(char ***s, char **buffer, int is_f);
int path_faild(char **buffer, char ***s, char *av);
/*============================ STR functions =============================*/
int _strlen(char *str);
int _strcmp(char *src, char *dest);
int _strcmp_echo(char *dest, char *src);
char *skip_space_tab_for_berror(char *buffer);
char *_strtok(char *str, char *dahawmitr);
char *_strdup(char *buffer);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int berror(int count, char *buffer, char *av);
void _putchar(char c);
void _puts(char *str);
void print_int(unsigned int n);
/*======================== End of STR functions ==========================*/
int new_pro(char ***s, char **buffer, char *av);
/*============================ path functions =============================*/
char *real_path(char **buffer, int *faild);
char *_getenvi();
void print_env(void);
/*======================== End of path functions ==========================*/
int interactive_mode(char *av);
int advnce_exit(char *buffer, char *av);
int _atoi(char *s);
int berror_exit(int count, char *n, char *av);
int _strcmp_exit(char *dest);


#endif
