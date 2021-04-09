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
			if (handle_args(input, tokens, argv[0]) == -1)
				status = call_to_execute(input, argv[0]);

		}
		free(input);
	} while (status);
	return (0);
}

/**
 * handle_args - function to handle logical operators
 * @str: the input string
 *
 * Return: 1 on success 0 otherwise
 **/
int handle_args(char *str, char **tokens, char *argv)
{
	int status = 1;
	char *arg = NULL;
	char *tmp = NULL;
	int i;

	for (i = 0; tokens[i]; i++)
	{
		if(_strncmp(tokens[i], "&&", 2) == 0)
		{
			tmp = _strdup(str);
			arg = _mystrtok2(tmp, "&&");
			while (arg)
			{
				status = call_to_execute(arg, argv);
				if (status != -1)
					arg = _mystrtok2(NULL, "&&");
				else
					arg = NULL;
			}
			return (1);
		}
		else if(_strncmp(tokens[i], "||", 2) == 0)
		{
			tmp = _strdup(str);
			arg = _mystrtok2(tmp, "||");
			while (arg)
			{
				status = call_to_execute(arg, argv);
				if (status != -1)
					arg = NULL;
				else
					arg = _mystrtok2(NULL, "||");
			}
			return (1);
		}
	}
	return (-1);
}
/**
 * call_to_execute - ready for execution
 * @input: the given input
 *
 * Return: 1 on sucess
 **/
int call_to_execute(char *inpt, char *arg)
{
	char **tokens = NULL;
	int (*f)(char **, char *);
	int status = -1;
	int len = 0;
	char *cmd = NULL;

	inpt = var_replacement(inpt);
	len = _length(inpt);
	tokens = tokenize(inpt, " \t", len);
	f = handle_built_in(tokens[0]);
	if (f == NULL)
	{
		cmd = _strdup(tokens[0]);
		tokens[0] = _which(tokens[0]);
		if (tokens[0] && access(tokens[0], X_OK) == 0)
		{
			status = execute(tokens[0], tokens);
			free_memory_tokens(tokens, NULL);
		}

		else
		{
			printf("%s: command not found\n", cmd);
			free_memory_tokens(tokens, NULL);
			status = -1;
		}
	}
	else
	{
		status = f(tokens, arg);
		free_memory_tokens(tokens, NULL);
	}
	return (status);
}
/**
 * _strncmp - function that compares n characters
 * @s1: the first string
 * @s2: the second string
 * @n: the number of characters to compare
 *
 * Return: 0 if the same, > 0 if s1 >s2 and < 0 if s1 < s2
 **/
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n ; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);

	}
	if (i == n)
		return (0);
	else
		return (-1);
}
