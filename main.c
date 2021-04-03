#include "holberton.h"
/**
 * main - entry point for the program
 * @ac: the number of argument
 * @av: array of the arguments
 * @env: the environment variable
 *
 * Return: always sucess
 **/
int main(int __attribute__((__unused__)) ac, char *argv[])
{
	char *input = NULL;
	char **tokens = NULL;
	int status = 1;
	int characterlen = 0;

	do {
		input = _getline(argv[0]);
		characterlen = _length(input);
		if (characterlen > 0 && input[0] != '\n')
		{
			tokens = tokenize(input, " \t", characterlen);
			tokens[0] = _which(tokens[0]);
			if (tokens[0] && access(tokens[0], X_OK) == 0)
				status = execute(tokens[0], tokens);
			else
				perror("./hsh");
		/**	free_memory_tokens(tokens);**/
		}
	} while (status);
	free(input);
	return (0);
}
