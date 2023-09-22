#include "shell.h"

/** 
 * parse_command - That determines the command type.
 * @command: parsed command.
 *
 * Return: constant representing the type of the command
 */
int parse_command(char *command)
{
	int n;
	char *internal_command[] = {"env", "exit", NULL};
	char *path = NULL;

	for (n = 0; command[n] != '\0'; n++)
	{
		if (command[n] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (n = 0; internal_command[n] != NULL; n++)
	{
		if (_strcmp(command, internal_command[n]) == 0)
			return (INTERNAL_COMMAND);
	}
	path = check_path(command);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}
	return (INVALID_COMMAND);
}

/**
 * execute_command - command executes a by their types.
 * @tokenized_command: the command form of tokenized. 
 * @command_type: The command type.
 *
 * Return: Nothing.
 */
void execute_command(char **tokenized_command, int command_type)
{
	void (*func)(char **command);

	if (command_type == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_command[0]), tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == INTERNAL_COMMAND)
	{
		func = get_func(tokenized_command[0]);
		func(tokenized_command);
	}
	if (command_type == INVALID_COMMAND)
	{
		print(shell_name, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(tokenized_command[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * check_path - That checks a command in the PATH.
 * @command: used command.
 *
 * Return: path of the command or NULL
 */
char *check_path(char *command)
{
	char **path_array = NULL;
	char *temp, *temp2, *path_cpy;
	char *path = _getenv("PATH");
	int n;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path, path_cpy);
	path_array = tokenizer(path_cpy, ":");
	for (n = 0; path_array[n] != NULL; n++)
	{
		temp2 = _strcat(path_array[n], "/");
		temp = _strcat(temp2, command);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(path_array);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(path_array);
	return (NULL);
}

/**
 * get_func - That retrieves a function based on the given command.
 * @command: That checks the mapping.
 *
 * Return: pointer to the function or null
 */
void (*get_func(char *command))(char **)
{
	int n;
	function_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	for (n = 0; n < 2; n++)
	{
		if (_strcmp(command, mapping[n].command_name) == 0)
			return (mapping[n].func);
	}
	return (NULL);
}

/**
 * _getenv - That gets the environment variable value.
 * @name: environment variable name.
 *
 * Return: a string representing the variables value.
 */
char *_getenv(char *name)
{
	char **my_environ;
	char *pair_ptr;
	char *name_cpy;

	for (my_environ = environ; *my_environ != NULL; my_environ++)
	{
		for (pair_ptr = *my_environ, name_cpy = name;
		     *pair_ptr == *name_cpy; pair_ptr++, name_cpy++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*name_cpy == '\0'))
			return (pair_ptr + 1);
	}
	return (NULL);
}
