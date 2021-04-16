#ifndef DEFINE_PROTO
#define DEFINE_PROTO
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>
#include <dirent.h>
#include <errno.h>

extern char **environ;

/**
 * struct alias_t - type of an alias object
 * @key: key of alias
 * @command: valud of alias
 *
 * Description: will hold all temporary aliases
 */
typedef struct alias_t
{
	char *key;
	char *command;
} alias_t;

/** alias_t **_aliases; **/

char **tokenize(char *input, char *separator, int len);
int _length(char *str);
char *cleaner(char *input);
int execute(char *arg, char **option);
void free_memory_tokens(char **tokens, char *token);
char *_mystrtok(char *str, char *del);
char *_mystrtok2(char *str, char *del);
char *_strcopy(char *dest, char *src);

/**
 * struct str - type of builtin type
 * @arg: argument of the function
 * @f: the function handler for the built in comand
 *
 * Description: will hold holl function handler of built in commands
 */
typedef struct str
{
	char *arg;
	int (*f)(char **argv, char *pname, int count);
} builtin_type;
char *_strdup(char *str);
int (*handle_built_in(char *command))(char **tk, char *pn, int c);
int handle_cd(char **tokens, char *pname, int count);
char *_get_environ(char *n, char **env);
int handle_args(char *str, char **tokens, char *argv);
int call_to_execute(char *input, char *arg);
int _strncmp(char *s1, char *s2, size_t n);
char *var_replacement(char *input, int st);
char *rep_input(char *ipt, char *nw_ipt, char *rplc_str, int iptlen, int vlen);
char *int_to_str(int n);
int _intlen(int n);
char *_getline(char *prName);
char *_which(char *command);
int customExit(char **tokens, char *prName, int count);
int checkNumber(char *token);
int getNumericValue(char *token, int len);
int _pow(int base, int exp);
int countTokens(char **tokens);
int _strcmp(char *s1, char *s2);
char *reallocateMemory(char **path, size_t *pathLength, size_t pIdx);
char *appendCommand(char *path, char *cm, size_t pIdx, size_t *pL);
void _signal(void);
void signalHandler(int sigInt);
int _setenv(char **tokens, char *pname, int count);
int _ls(char **tokens, char *pname, int count);
void _custom_ls(const char *dir, int op_a, int op_l);
int _unsetenv(char **tokens, char *pname, int count);
char *getKey(char *var);
char *createNewEnvStr(char **tokens);
int _alias(char **tokens, char *pname, int count);
int getCommandType(char *command);
int _strContains(char *str, char c);
alias_t *addAlias(char *key, char *command);
int countAliases(void);
alias_t *updateAlias(char *key, char *command);
void printAlias(char *key);
void printAllAliases(void);
char *checkCommandAlias(char *key);
char *concatTokens(char **tokens, char *newValue);
int handleSubaliases(char *input, char *argi);
char *_strcat(char *dest, char *src);
void setcustomenv(char *name, char *value);
int cd_to_path(char **tokens, char *prName);
int handle_semicolon(char *str, char *argv);
#endif
