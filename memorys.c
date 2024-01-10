#include "shelll.h"

/**
 * bfrees - freeing pointer from address
 * @ptr: pointer address
 *
 * Return: 1 success 0 failure
 */
int bfrees(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
