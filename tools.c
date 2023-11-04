#include "main.h"


int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
void free_grid(char **s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}