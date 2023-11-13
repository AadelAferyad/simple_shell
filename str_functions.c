#include "main.h"

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