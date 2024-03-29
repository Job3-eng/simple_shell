#include "shelll.h"

/**
 * is_cmds - determining executable file
 * @info: structure
 * @path: file path
 *
 * Return: 1 succes, 0 failure
 */
int is_cmds(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_charss - duplicating char
 * @pathstr: path str
 * @start: starting  point index
 * @stop: stopping point index
 *
 * Return: pointer for the buff
 */
char *dup_charss(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int a = 0, l = 0;

	for (l = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buf[l++] = pathstr[a];
	buf[l] = 0;
	return (buf);
}

/**
 * find_path - finding cmds
 * @info: structure
 * @pathstr: path str
 * @cmd: cmd
 *
 * Return: cmd path or NULL
 */
char *find_paths(info_t *info, char *pathstr, char *cmd)
{
	int a = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[a] || pathstr[a] == ':')
		{
			path = dup_chars(pathstr, curr_pos, a);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[a])
				break;
			curr_pos = a;
		}
		a++;
	}
	return (NULL);
}
