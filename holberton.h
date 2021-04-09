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
typedef struct alias_t
{
	char *key;
	char *command;
} alias_t;

alias_t **_aliases;

char **tokenize(char *input, char *separator, int len);
int _length(char *str);
char *cleaner(char *input);
int execute(char *arg, char **option);
void free_memory_tokens(char **tokens);
char *_mystrtok(char *str, char *del);
char *_strcopy(char *dest, char *src);
char *_getline(char *prName);
char *_which(char *command);
void customExit(char **tokens, int count, char *prName);
int checkNumber(char *token);
int getNumericValue(char *token, int len);
int _pow(int base, int exp);
int countTokens(char **tokens);
int _strcmp(char *s1, char *s2);
char *reallocateMemory(char **path, size_t *pathLength, size_t pIdx);
char *appendCommand(char *path, char *command, size_t pIdx, size_t *pathLength);
void _signal(void);
void signalHandler(int sigInt);
char *_setenv(char **tokens, int count);
char *_unsetenv(char **tokens, int count);
char *getKey(char *var);
char *createNewEnvStr(char **tokens);
int _alias(char **tokens, int count);
int getCommandType(char *command);
int _strContains(char *str, char c);
alias_t *addAlias(char *key, char *command);
int countAliases(void);
alias_t *updateAlias(char *key, char *command);
void printAlias(char *key);
void printAllAliases(void);
char *checkCommandAlias(char * key);
char *concatTokens(char **tokens, char *newValue);
#endif
