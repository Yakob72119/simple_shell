#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>


/*constant variables*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define INVALID_COMMAND -1
#define PATH_COMMAND 3


#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct map - That maps commands name to a function. 
 *
 *@command_name: The command name.
 *@func: the function that executes the command
 */

typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/*functions in helpers*/
void print(char *, int);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void _strcpy(char *, char *);

/*functions in helpers2*/
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/*functions in helpers3*/
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int);
void remove_comment(char *);

/*functions in utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/*functions in built_in*/
void env(char **);
void quit(char **);

/*functions in main*/
extern void non_interactive(void);
extern void initializer(char **current_command, int type_command);

/*functions in getline*/
char *custom_getline();
int main();


#endif /*SHELL_H*/