#include "shelll.h"

/**
 * _strcpys - coping string
 * @dest: destinations
 * @src: source
 *
 * Return: ptr to destn
 */
char *_strcpys(char *dest, char *src)
{
	int a = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = 0;
	return (dest);
}

/**
 * _strdups - duplicating string
 * @str: string
 *
 * Return: ptr for  duplicat string
 */
char *_strdups(const char *str)
{
	int length = 0;
	char *rets;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	rets = malloc(sizeof(char) * (length + 1));
	if (!rets)
		return (NULL);
	for (length++; length--;)
		rets[length] = *--str;
	return (rets);
}

/**
 * _putss - printing input
 * @str: the str
 *
 * Return: void
 */
void _putss(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
}

/**
 * _putchars - writting characters
 * @c: char
 *
 * Return: success 1 .for failure -1
 */
int _putchars(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
