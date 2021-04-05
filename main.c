#include "holberton.h"
/**
 * main - entry point for the program
 * @argc: the number of argument
 * @argv: array of the arguments
 *
 * Return: always sucess
 **/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char *input = NULL;
	char **tokens = NULL;
	int status = 1;
	int characterlen = 0;

	_signal();
	signal(SIGINT, SIG_IGN);
	do {
		input = _getline(argv[0]);
		characterlen = _length(input);
		if (characterlen > 0 && input[0] != '\n')
		{
			tokens = tokenize(input, " \t", characterlen);
			if (_strcmp(tokens[0], "exit") == 0)
			{
				customExit(tokens, countTokens(tokens), argv[0]);
				free_memory_tokens(tokens);
				continue;
			}
			tokens[0] = _which(tokens[0]);
			if (tokens[0] && access(tokens[0], X_OK) == 0)
				status = execute(tokens[0], tokens);
			else
				perror("./hsh");
			free_memory_tokens(tokens);
		}
		free(input);
	} while (status);
	return (0);
}
