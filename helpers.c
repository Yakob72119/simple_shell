#include "shell.h"

/**
 *tokenizer - This func tokenizes the input string and stores it in an array.
 *@input_string: The string to be tokenized.
 *@delim: The delimiter to be used, which should be a one-character string.
 *
 *Return: An array of tokens.
 */

char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 *print - displays a string on the standard output.
 *@string: the string to be displayed.
 *@stream: the output stream.
 *
 *Return: nothing
 */
void print(char *string, int stream)
{
	int n = 0;

	for (; string[n] != '\0'; n++)
		write(stream, &string[n], 1);
}

/**
 *remove_newline - delete new line in the string.
 *@str: The string to be used.
 *
 *
 *Return: void
 */

void remove_newline(char *str)
{
	int n = 0;

	while (str[n] != '\0')
	{
		if (str[n] == '\n')
			break;
		n++;
	}
	str[n] = '\0';
}

/**
 *_strcpy - copy the string in buffer.
 *@source: location to copy string.
 *@dest: dist to paste.
 *
 * Return: Nothing
 */

void _strcpy(char *source, char *dest)
{
	int n = 0;

	for (; source[n] != '\0'; n++)
		dest[n] = source[n];
	dest[n] = '\0';
}

/**
 *_strlen - count the length of the string.
 *@string: counting the string.
 *
 * Return: count result.
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}

