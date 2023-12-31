#include "main.h"
/**
 * skip_space_tab_for_berror - Skips leading spaces
 * and tabs in a string.
 * @buffer: Input string.
 *
 * Return: newly allocated string without leading spaces and tabs,
 *  or NULL if allocation fails.
 */
char *skip_space_tab_for_berror(char *buffer)
{
	int i = 0, count = 0, is = -1, j, k = 0;
	char *temp = NULL;

	for (; buffer[i]; i++) /*"   d          d   "*/
	{
		if (buffer[i] != 32 && buffer[i] != 9)
		{
			if (is < 0)
				is = i;
			count++;
		}
		else if (is > 0 || is == 0)
			break;
	}
	if (count == 0)
		return (NULL);
	temp = malloc(count + 1);
	if (!temp)
		return (NULL);
	j = is;
	while (k < count)
	{
		temp[k] = buffer[j];
		j++;
		k++;
	}
	temp[k] = '\0';
	return (temp);
}
/**
 * advnce_exit - Handles "exit" command with additional arguments.
 * @buffer: Input string containing the "exit" and arguments.
 * @av: Command-line arguments.
 *
 * Return: The exit status specified in the command,
 *  or 2 if there is an error.
 */
int advnce_exit(char *buffer, char *av)
{
	int i = 0; /*exit */
	char *tmp = NULL;

	tmp = _strdup(&buffer[5]);
	i = _atoi(tmp);
	if (i < 0)
	{
		berror_exit(1, tmp, av);
		free(tmp);
		return (2);
	}
	free(tmp);
	return (i);
}
/**
 * _strcmp_exit - Compares a string with the "exit" command.
 * @dest: Input string to be compared with "exit".
 *
 * Return: 0 if not equal, 1 if equal,
 *  2 if "exit" with numeric argument,
 *  3 if "exit" with alphabetic argument.
 */
int _strcmp_exit(char *dest)
{
	int i = 0, j = 0;
	char *src;

	src = "exit";
	for (; src[i]; i++)
	{
		if (src[i] != dest[i])
			return (0);
	}
	if (dest[i] != '\0')
	{
		j = i;
		while (dest[j])
		{
			if (src[i] == '\0' && (dest[j] == 32 || dest[j] == 9))
				j++;
			else if (src[i] == '\0' && ((dest[j] >= 48 && dest[j] <= 57 &&
					dest[j - 1] == 32) || dest[j] == '-'))
				return (2);
			else if (src[i] == '\0' && ((dest[j] >= 'A' &&
					dest[j] <= 'Z' && dest[j - 1] == 32)))
				return (3);
			else if (src[i] == '\0' && ((dest[j] >= 'a' &&
					dest[j] <= 'z' && dest[j - 1] == 32)))
				return (3);
			else
				return (0);
		}
	}
	return (1);
}
/**
 * _atoi - Converts a string to an integer.
 * @s: Input string.
 *
 * Return: The integer value of the string,
 *  or -1 on error.
 */
int _atoi(char *s)
{
	int i = 0;

	int h = 0;

	int bool = 0;
	int sign = 1;
	int negative = 0;

	while (s[i] != '\0')
	{
		if ((s[i] >= 'A' && s[i] <= 'Z'))
			return (-1);
		else if ((s[i] >= 'a' && s[i] <= 'z'))
			return (-1);
		if (bool == 0 && s[i] == '-')
		{
			negative++;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{
			h = h * 10 + (int)s[i] - 48;
			bool = 1;
		}
		if (negative % 2 == 0)
		{
			sign = 1;
		}
		else
			sign = -1;
		if (bool == 1 && (s[i] < 48 || s[i] > 57) && s[i + 1] == '\0')
		{
			return (h * sign);
		}
		i++;
	}
	return ((h == 0) ? -1 : h * sign);
}
/**
 * berror_exit - Handles error messages for the "exit" .
 * @count: Error count.
 * @n: Numeric argument causing the error.
 * @av: Command-line arguments.
 *
 * Return: 1 if memory allocation fails,
 *  2 if exit command error.
 */
int berror_exit(int count, char *n, char *av)
{
	char *tmp = skip_space_tab_for_berror(n);

	if (!tmp)
		return (1);
	_puts(av);
	_puts(": ");
	print_int(count);
	_puts(": ");
	_puts("exit");
	_puts(": Illegal number: ");
	_puts(tmp);
	_puts("\n");
	free(tmp);
	return (2);
}
