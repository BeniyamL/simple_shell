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

extern char **environ;
//int global_status = 1;

char **tokenize(char *input, char *separator, int len);
int _length(char *str);
char *cleaner(char *input);
int execute(char *arg, char **option);
void free_memory_tokens(char **tokens, char *token);
char *_mystrtok(char *str, char *del);
char *_mystrtok2(char *str, char *del);
char *_strcopy(char *dest, char *src);
typedef struct str
{
	char *arg;
	int (*f)(char **argv, char *pname);
} builtin_type;
char *_strdup(char *str);
int (*handle_built_in(char *command))(char **tokens, char *pname);
int handle_cd(char **tokens, char *pname);
char *_get_environ(char *n, char **env);
int handle_args(char *str, char **tokens, char *argv);
int call_to_execute(char *input, char *arg);
int _strncmp(char *s1, char *s2, size_t n);
char *var_replacement(char *input);
char *replace_input(char *input, char *new_input, char *rplc_str, int inptlen, int varlen);
char *int_to_str(int n);
int _intlen(int n);


char *_getline(char *prName);
char *_which(char *command);
int customExit(char **tokens, char *prName);
int checkNumber(char *token);
int getNumericValue(char *token, int len);
int _pow(int base, int exp);
int countTokens(char **tokens);
int _strcmp(char *s1, char *s2);
char *reallocateMemory(char **path, size_t *pathLength, size_t pIdx);
char *appendCommand(char *path, char *command, size_t pIdx, size_t *pathLength);
void _signal(void);
void signalHandler(int sigInt);
#endif
