#include "main.h"

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
