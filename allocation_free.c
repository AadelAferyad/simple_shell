#include "main.h"


int count_words(char *buffer)
{
	int words = 0, i = 0;

	if (_strcmp_echo(buffer))
		return (count_words_echo(buffer));
	if (buffer[0] != 32)
		words++;
	while (buffer[i])/*"   this     is a example " = 4*/
	{
		if (buffer[i] == 32 && buffer[i + 1] != 32 && buffer[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

char *alloc_words_buffer(char *buffer, int *index_buffer)
{
	char *s;
	int i = 0, j = 0;

	if (buffer[i] == 34)
		return (alloc_words_echo(&buffer[1], index_buffer));
	while (buffer[i] != 32 && buffer[i] )/*"echo "    " "*/
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
char **allocate_argv_and_set(char *buffer)
{
	char **s;
	int len = count_words(buffer), i = 0, j = 0, k = 0;/*"echo "    ""*/

	s = malloc(sizeof(char *) * (len + 1));
	if (!s)
		return (NULL);
	while (i < len)
	{
		while (buffer[j])/*"echo "    "\0"*/
		{
			if (buffer[j] != 32)/*" echo "   " "*/
			{
				s[i] = alloc_words_buffer(&buffer[j], &j);
				if (!s[i])
				{
					while (k < i)
					{
						free(s[k]);
						k++;
					}
					free(s);
					return (NULL);
				}
				break;
			}
			j++;
		}
		i++;
	}
	s[i] = NULL;
	return (s);
}



void free_grid(char **s)
{
	int i = 0;

	if (!s)
		return;
	for (;s[i]; i++)
		free(s[i]);
	free(s);
}