#include "main.h"
/**
 * count_words_echo - Count the number of words in "echo".
 * @buffer: The input string containing the "echo" command.
 * Return: The number of words in the "echo" command string.
 */
int count_words_echo(char *buffer)
{
	int i = 0, words = 0;

	if (buffer[0] != 32)
		words++;
	while (buffer[i]) /*"echo "   " "*/
	{
		if (buffer[i] == 34)
		{
			i++;
			while (buffer[i] != 34)
				i++;
		}
		if (buffer[i] == 32 && buffer[i + 1] != 32 && buffer[i + 1])
			words++;
		i++;
	}
	return (words);
}
/**
 * alloc_words_echo - Allocate memory for a word in an "echo".
 * @buffer: The input buffer containing the "echo".
 * @index_buffer: Pointer to the index in the buffer.
 * Return: A pointer to the allocated memory for a word in the "echo".
 */
char *alloc_words_echo(char *buffer, int *index_buffer)
{
	char *s;
	int i = 1, j = 0;

	while (buffer[i] != 34 && buffer[i]) /*"echo "    " "*/
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