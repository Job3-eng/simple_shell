#include "shelll.h"

/**
 * _eputss - printing inputs string
 * @str: string being printed
 *
 * Return: empty
 */
void _eputss(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_eputchar(str[a]);
		a++;
	}
}

/**
 * _eputchars - writting characters c
 * @c: The char for printing
 *
 * Return: 1 success -1 error
 */
int _eputchars(char c)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}

/**
 * _putfds - writting c to fd
 * @c: char to be printed
 * @fd:  filedescriptor
 *
 * Return:  1 success -1  for error
 */
int _putfds(char c, int fd)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 * _putsfds - printing input
 * @str: string
 * @fd: filedescriptor
 *
 * Return: no. of char.
 */
int _putsfds(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}
