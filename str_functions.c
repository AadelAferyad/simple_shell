#include "main.h"
/**
 * _strchr -  locates a character in a string
 * @s: pointer to string
 * @c: pointer to character
 * Return: if c found return occurence if its not return NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	if (s[i] == c)
		return (&s[i]);

	return (NULL);
}
/**
 * _strcat - concatenates two strings
 * @dest: pointer to destination
 * @src: pointer to source
 * Return: Destination
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	for (; dest[i] != '\0'; i++)
	{
		continue;
	}

	for (; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * _strcpy - copy string from src to dest
 * @dest: pointer to dest char
 * @src: pointer to src char
 * Return: return destStart
 */
char *_strcpy(char *dest, char *src)
{
	char *destStart = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (destStart);
}
/**
 * _strncmp - Compare the first n characters of two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The number of characters to compare.
 * Return: 0 if Success, -1 Failure.
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	for (; i < n; i++)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
		{
			return (-1);
		}
	}
	return (0);
}
