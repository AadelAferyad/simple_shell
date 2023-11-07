#include "main.h"


int _strcmp(char *src, char *dest)/* "exit" exit*/
{
	int i = 0;

	if (!src || !dest)
		return (0);
	for (; src[i] && dest[i]; i++)
	{
		if (src[i] != dest[i])
			return (0);
	}
	return ((src[i] == dest[i]) ? 1 : 0);
}

int _strcmp_echo(char *dest)
{
	int i = 0;
	char *s = "echo";
	for (;s[i] && dest[i]; i++)
	{
		if (s[i] != dest[i])
			return (0);
	}
	return ((s[i] == '\0') ? 1 : 0);
}


