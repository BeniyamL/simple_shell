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
#endif
