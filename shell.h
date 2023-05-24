#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char **environ;

/**
* struct fmt_check - types of data and their function
* @ltr: the type of data
* @type: pointer to function for the type
*/
typedef struct fmt_check
{
	char *ltr;
	int (*type)(va_list *args, const char *format, int i);
} fmt_check;


/**
* struct fmt - types of data and their function
* @ltr: the type of data
* @type: pointer to function for the type
*/
typedef struct fmt
{
	char *ltr;
	int (*type)(va_list *args);
} fmt;


char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int len);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);

int parse(char *line, int token_count, char *av[], int cmd_count);
void free_mem(char *line, char **ar1, char *dup_line, char **ar2);
int num_count(char *line);

int exe(char *line, char **ar, char *dup_line, char **tkn_chk, char **av,
int failed_cmds);

int check_builtin(char *line, char **ar1, char *dup_line, char **ar2);
void change_dir(char **ar);

void execute_path(char *p, char **tokens);
int find_on_path(char **tokens);
int search_path(char *p, char **tokens);

int _printf(const char *format, ...);
int check_format(va_list *args, const char *format, int i);

void _puts(char *str);
int print_string(va_list *args);
int print_digit(va_list *args);
void get_digits(int n);
int _putchar(char c);


#endif /* _SHELL_H */
