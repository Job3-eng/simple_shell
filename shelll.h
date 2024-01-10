#ifndef _SHELLL_H_
#define _SHELLL_H_

#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


/* for cmd chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/*  r/w buffer */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for cmd chain */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* to  convert the numbers */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* for system getline() 1 */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr -  linked list
 * @num:  field number
 * @str: str
 * @next: pointing next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo -functions with  pseudo-arguementsfor passing
 * @arg: generated str.
 * @argv: generated string array.
 * @path: path for the string.
 * @argc: counting arg
 * @line_count: counting error
 * @err_num: code error
 * @linecount_flag: cointing inputs
 * @fname: filename
 * @env: copy of local linked lists
 * @environ: modified
 * @history: history of thenode
 * @alias: aliasing node
 * @env_changed: changing enviromentn
 * @status: returning status
 * @cmd_buf: pointer address for command
 * @cmd_buf_type: command type
 * @readfd: directory for reading input
 * @histcount: counting the line numbers
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - containing string  builtin
 * @type: the builting flag
 * @func: functions
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* string.c function */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
/* shloop.c function */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* _parsers.c function */
int is_cmds(info_t *, char *);
char *dup_charss(char *, int, int);
char *find_paths(info_t *, char *, char *);

/* loophshs.c function */
int loophshs(char **);

/* errorss.c function */
void _eputss(char *);
int _eputchars(char);
int _putfds(char c, int fd);
int _putsfds(char *str, int fd);

/* string1s.c  function*/
char *_strcpys(char *, char *);
char *_strdups(const char *);
void _putss(char *);
int _putchars(char);

/* exitss.c functions*/
char *_strncpys(char *, char *, int);
char *_strncats(char *, char *, int);
char *_strchrs(char *, char);

/* tokenizers.c functions */
char **strtows(char *, char *);
char **strtow2s(char *, char);

/* _reallocs.c functions*/
char *_memsets(char *, char, unsigned int);
void ffrees(char **);
void *_reallocs(void *, unsigned int, unsigned int);

/* memorys.c the functions*/
int bfrees(void **);

/*  functions */

/* historys.c functions*/
char *get_history_files(info_t *info);
int write_historys(info_t *info);
int read_historys(info_t *info);
int build_history_lists(info_t *info, char *buf, int linecount);
int renumber_historys(info_t *info);

/*the function errors1s.c */
int _erratois(char *);
void print_errors(info_t *, char *);
int print_ds(int, int);
char *convert_numbers(long int, int, int);
void remove_commentss(char *);

/*the function builtins.c */
int _myexits(info_t *);
int _mycds(info_t *);
int _myhelps(info_t *);

/*getlines.c the function*/
ssize_t get_inputs(info_t *);
int _getlines(info_t *, char **, size_t *);
void sigintHandlers(int);

/*the function getinfos.c */
void clear_infos(info_t *);
void set_infos(info_t *, char **);
void free_infos(info_t *, int);

/* getenvs.c the function*/
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* builtins1.c the function*/
int _myhistorys(info_t *);
int _myalias(info_t *);

/* l1ists.c functions*/
list_t *add_nodes(list_t **, const char *, int);
list_t *add_node_ends(list_t **, const char *, int);
size_t print_list_strs(const list_t *);
int delete_node_at_indexs(list_t **, unsigned int);
void free_lists(list_t **);

/* _environ1.c the function */
char *_getenvs(info_t *, const char *);
int _myenvs(info_t *);
int _mysetenvs(info_t *);
int _myunsetenvs(info_t *);
int populate_env_list(info_t *);
/* listings1.c functions */
size_t list_length(const list_t *);
char **lists_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* _vars.c functions*/
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* functions for _varsin.c */
int is_chains(info_t *, char *, size_t *);
void checking_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_aliass(info_t *);
int replace_varss(info_t *);
int replace_strings(char **, char *);
/* functions atoiim.c */
int interactives(info_t *);
int is_delimeter(char, char *);
int _isalphas(int);
int _atoiim(char *);
#endif
