#include "holberton.h"
/**
 * main - entry point for the program
 * @ac: the number of argument
 * @av: array of the arguments
 * @env: the environment variable
 *
 * Return: always sucess
 **/
int main()
{
	size_t size = 0;
	char *input = NULL;
	char **tokens = NULL;
	int len = 0;
	int status = 1;
	int characterlen = 0;

	do {
		write(STDOUT_FILENO, "$:) ", 4);
		characterlen = getline(&input, &size, stdin);
		if (characterlen > 0 && input[0] != '\n')
		{
			len = _length(input);
			tokens = tokenize(input, " \t", len);
			/**
			tokens[0] = validate(tokens[0]);
			**/
			if (tokens[0] && access(tokens[0], X_OK) == 0)
				status = execute(tokens[0], tokens);
			else
				perror("./hsh");
			free_memory_tokens(tokens);
		}
	} while (status);
	free(input);
	return (0);
}
