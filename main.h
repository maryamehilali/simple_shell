#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#define MAX_SIZE 1024

extern char **environ;
/**
 * struct builtin - a struct for pointers to the builtin fucntions,
 * @str: the command entered by the user,
 * @fct: the builtin function corresponding to the user's command.
 */
typedef struct builtin
{
	char *str;
	void (*f)(char **);
} builtin_fct;

extern char **environ;
char *user_input(void);
int _getline(char **, size_t *);
char **tokenize(char *string, char *delim);
char *find_command(char *command);
int  _strlen(char *s);
int _strncmp(const char *s1, const char *s2, int  n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void print_env(char **);
void free_commands_array(char **array);
char *_concat(char *n, char *s, char *v);
char *_getenv(const char *n);
void _setenv(char **arg);
void _unsetenv(char **arg);
void exitbuiltin(char **);
int _atoi(char *);
void execute(char *, char **);
void (*get_builtin(char *))(char **);

#endif
