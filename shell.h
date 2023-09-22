#ifndef simple_shell
#define simple_shell

#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/*constant variables*/
#define EXTERNAL_COMMAND 1
#define INVALID_COMMAND -1
#define INTERNAL_COMMAND 2
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

extern char *shell_name;
extern char *line;
extern char **commands;
extern int status;
extern char **environ;


/*functions in helperstwo*/
char *_strcat(char *, char *);
int _strcmp(char *, char *);
char *_strchr(char *, char);
int _strcspn(char *, char *);
int _strspn(char *, char *);


/*functions in utils*/
char *_getenv(char *);
void execute_command(char **, int);
char *check_path(char *);
int parse_command(char *);
void (*get_func(char *))(char **);


/*functions in helpers*/
char **tokenizer(char *, char *);
void remove_newline(char *);
void print(char *, int);
int _strlen(char *);
void _strcpy(char *, char *);


/*functions in helpersthree*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void remove_comment(char *);
int _atoi(char *);
void ctrl_c_handler(int);
char *_strtok_r(char *, char *, char **);

/*functions in main*/
extern void initializer(char **current_command, int type_command);
extern void non_interactive(void);

/*functions in built_in*/
void quit(char **);
void env(char **);

#endif

