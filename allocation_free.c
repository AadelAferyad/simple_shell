#include "main.h"
/**
 * count_words - Count the number of words in a string.
 * @buffer: The input string.
 * Return: The number of words in the string.
 */
int count_words(char *buffer)
{
	int words = 0, i = 0;

	if (_strcmp_echo(buffer))
		return (count_words_echo(buffer));
	if (buffer[0] != 32)
		words++;
	while (buffer[i]) /*"   this     is a example " = 4*/
	{
		if (buffer[i] == 32 && buffer[i + 1] != 32 && buffer[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}
/**
 * alloc_words_buffer - Allocate memory for a word in the buffer.
 * @buffer: The input buffer.
 * @index_buffer: Pointer to the index in the buffer.
 * Return: A pointer to the allocated memory.
 */
char *alloc_words_buffer(char *buffer, int *index_buffer)
{
	char *s;
	int i = 0, j = 0;

	if (buffer[i] == 34)
		return (alloc_words_echo(&buffer[1], index_buffer));
	while (buffer[i] != 32 && buffer[i]) /*"echo "    " "*/
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	*index_buffer = *index_buffer + i;
	while (j < i)
	{
		s[j] = buffer[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}
/**
 * allocate_argv_and_set - Allocate memory for an array of words.
 * @buffer: The input buffer containing words.
 * @f: Pointer to an integer indicating failure (1) or success (0).
 * Return: A dynamically allocated array of words or NULL on failure.
 */
char **allocate_argv_and_set(char *buffer, int *f)
{
	char **s;
	int len = count_words(buffer), i, j = 0, k; /* "echo "    "" */

	if (len == 0)
	{
		if (f)
			*f = 0;
		return (NULL);
	}
	s = malloc(sizeof(char *) * (len + 1));
	if (!s)
	{
		if (f)
			*f = 1;
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		for (; buffer[j] == ' '; j++)
			; /* Skip spaces */
		if (buffer[j])
		{
			s[i] = alloc_words_buffer(&buffer[j], &j);
			if (!s[i])
			{
				for (k = 0; k < i; k++)
					free(s[k]);
				free(s);
				if (f)
					*f = 1;
				return (NULL);
			}
		}
	}
	s[i] = NULL;
	return (s);
}
/**
 * free_grid - Free memory allocated for a 2D array.
 * @s: The 2D array.
 */
void free_grid(char **s)
{
	int i = 0;

	if (!s)
		return;
	for (; s[i]; i++)
		free(s[i]);
	free(s);
}
