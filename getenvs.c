#include "shelll.h"

/**
 * get_environs - returning string array environment
 * @info: Structure with the  args
 * Return: 0 success
 */
char **get_environs(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenvs - Removing  environ variable
 * @info: Structure with the  args.
 *  Return: 1 for  deleting, 0 otherwise
 * @var: env properti
 */
int _unsetenvs(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t a = 0;
	char *b;

	if (!node || !var)
		return (0);

	while (node)
	{
		b = starts_with(node->str, var);
		if (b && *b == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), a);
			a = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		a++;
	}
	return (info->env_changed);
}

/**
 * _setenvs - Initializing environ  variable.
 * @info: Structure with the  args.
 * @var: string
 * @value:  value
 *  Return:  0 success
 */
int _setenvs(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
