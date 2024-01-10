#include "shelll.h"

/**
 * _memsets - filling the  memory
 * @s: pointer area
 * @b:  byte for pointer
 * @n: amnt for bytes
 * Return: pointer
 */
char *_memsets(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = b;
	return (s);
}

/**
 * ffrees - freeing string
 * @pp: strings
 */
void ffrees(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _reallocs - reallocating memory
 * @ptr: pointer
 * @old_size: 1st size
 * @new_size: new size
 *
 * Return: pointer
 */
void *_reallocs(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *b;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	b = malloc(new_size);
	if (!b)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		b[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (b);
}
