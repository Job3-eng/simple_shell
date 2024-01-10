#include "shelll.h"

/**
 **_strncpys - coping  a string
 *@dest: string copied intto
 *@src: sources string
 *@n: amnt of char  copied
 *Return: concat string
 */
char *_strncpys(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncats - string concatenation
 *@dest: 1st string
 *@src: 2nd string
 *@n: max  amnt of bytes
 *Return:  string
 */
char *_strncats(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchrs - locating characters
 *@s: string being parsed
 *@c: searched character
 *Return: pointer
 */
char *_strchrs(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
