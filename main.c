#include "shell.h"

	char *shell_name = NULL;
	int status = 0;
	char **commands = NULL;
	char *line = NULL;
	
/**
 * main - Shell main code starting.
 * @argc: The number of passed arguments.
 * @argv: A parsed program arguments.
 *
 * Return: 0 when it success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char **current_command = NULL;
	int x, type_command = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];
	while (1)
	{
		non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");

		for (x = 0; commands[x] != NULL; x++)
		{
			current_command = tokenizer(commands[x], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);

			initializer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);
	return (status);
}
