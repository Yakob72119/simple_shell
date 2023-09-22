#include "shell.h"

/**
 *_strcmp - String comparison.
 *@first: the first string.
 *@second: the second string.
 *
 * Return: difference between the strings.
 */
int _strcmp(char *first, char *second)
{
	int n = 0;

	while (first[n] != '\0')
	{
		if (first[n] != second[n])
			break;
		n++;
	}
	return (first[n] - second[n]);
}

/**
 *_strcat - mearge two strings.
 *@destination: string to be mearge.
 *@source:  string to mearge.
 *
 * Return: mearged new string.
 */
char *_strcat(char *destination, char *source)
{
	char *new_string =  NULL;
	int len_dest = _strlen(destination);
	int len_source = _strlen(source);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	_strcpy(destination, new_string);
	_strcpy(source, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}

/**
 *_strspn - produces the length of a prefix.
 *@str1: search string.
 *@str2: used string.
 *
 *Return: the number of bytes in the first five bytes are accept.
 */
int _strspn(char *str1, char *str2)
{
	int match = 0;
	int n = 0;

	while (str1[n] != '\0')
	{
		if (_strchr(str2, str1[n]) == NULL)
			break;
		match++;
		n++;
	}
	return (match);
}

/**
 *_strcspn - computes the part of str1 that formed from char not found in str2.
 *@str1: search string.
 *@str2: used string.
 *
 *Return: the index of str1 exists in str2.
 */
int _strcspn(char *str1, char *str2)
{
	int len = 0, n;

	for (n = 0; str1[n] != '\0'; n++)
	{
		if (_strchr(str2, str1[n]) != NULL)
			break;
		len++;
	}
	return (len);
}

/**
 *_strchr - that gets a char in a string.
 *@s: search string.
 *@c: checked char.
 *
 *Return: pointer the char in a string.
 */
char *_strchr(char *s, char c)
{
	int n = 0;

	for (; s[n] != c && s[n] != '\0'; n++)
		;
	if (s[n] == c)
		return (s + n);
	else
		return (NULL);
}

