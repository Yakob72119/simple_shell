#include "shell.h"

/**
 *_strtok_r - string tokenizer.
 *@string: string has to be tokenized.
 *@delim: the delimiter to tokenize a string.
 *@save_ptr: pointer to next token.
 *
 *Return: The next token.
 */
char *_strtok_r(char *string, char *delim, char **save_ptr)
{
	char *finish;

	if (string == NULL)
		string = *save_ptr;

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	string += _strspn(string, delim);
	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	finish = string + _strcspn(string, delim);
	if (*finish == '\0')
	{
		*save_ptr = finish;
		return (string);
	}

	*finish = '\0';
	*save_ptr = finish + 1;
	return (string);
}

/**
 * _atoi - That changes the string to an integer.
 * @s: the changed string.
 *
 * Return: converted intiger.
 */
int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			n = (n * 10) + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n);
}

/**
 * _realloc - reallocate the memory space.
 * @ptr: previously allocated memory.
 * @old_size: pointer size.
 * @new_size: size of allocated memory.
 *
 * Return: pointer to the new memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int n;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			for (n = 0; n < min(old_size, new_size); n++)
				*((char *)temp_block + n) = *((char *)ptr + n);
			free(ptr);
			return (temp_block);
		}
		else
			return (NULL);

	}
}

/**
 * ctrl_c_handler - handles CTRL-C command.
 * @signum: number of the signal.
 *
 * Return: nothing.
 */
void ctrl_c_handler(int signum)
{
	if (signum == SIGINT)
		print("\n($) ", STDIN_FILENO);
}

/**
 * remove_comment - Ignores everything after a num char.
 * @input: input.
 *
 * Return: nothing
 */
void remove_comment(char *input)
{
	int n = 0;

	if (input[n] == '#')
		input[n] = '\0';
	while (input[n] != '\0')
	{
		if (input[n] == '#' && input[n - 1] == ' ')
			break;
		n++;
	}
	input[n] = '\0';
}

