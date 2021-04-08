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
	int (*f)(char **);

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
				continue;
			}
			f = handle_built_in(tokens[0]);
			if (f == NULL)
			{
				tokens[0] = _which(tokens[0]);
				if (tokens[0] && access(tokens[0], X_OK) == 0)
					status = execute(tokens[0], tokens);
				else
					perror("./hsh");
			}
			else
			{
				f(tokens);
			}
		free_memory_tokens(tokens, NULL);
		}
		free(input);
	} while (status);
	return (0);
}
