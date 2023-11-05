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
	for (;s[i]; i++)
		free(s[i]);
	free(s);
}
void skip_space_buffer(char **buffer)
{
	int i = 0, offsit = 0;

	/*two cases : "    /bin/ls ||/bin      /ls"
		"  /bin/ls" == [' ', ' ', ' ', '/', 'b', 'i', 'n', '/', '/', 'l', 's']
	*/

	while (buffer[i])
	{
		
	}
}