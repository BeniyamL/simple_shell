#include "holberton.h"
/**
 * tokenize - function that splits a string
 * @input: the given string
 * @separator: the delimiter
 * @length: the lenght of a string
 *
 * Return: the tokens on success or NULL otherwise
 **/
char **tokenize(char *input, char *separator, int length)
{
	char *token;
	char **tokens;
	int i = 0;

	input = cleaner(input);
	tokens = malloc(sizeof(char) * (length + 1));
	if (tokens == NULL)
		return (NULL);
	token = _mystrtok(input, separator);
	while (token)
	{
		tokens[i] = token;
		token = _mystrtok(NULL, separator);
		i++;
	}
	tokens[i] = '\0';
	return (tokens);

}

/**
 * cleaner - function that trims empty spaces and new lines
 * @input: the given string
 *
 * Return: the cleaned string
 **/
char *cleaner(char *input)
{
	int i, j;

	i = 0;
	j = 0;
	while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
	{
		i++;
	}
	while (input[i + j] != '\0')
	{
		input[j] = input[i + j];
		j++;
	}
	input[j] = '\0';

	i = 0;
	j = -1;
	while (input[i] != '\0')
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
		{
			j = i;
		}
		i++;
	}
	input[j + 1] = '\0';
	return (input);
}

/**
 * _length - function that finds the length of a string
 * @str: the given string
 *
 * Return: the length of a string
 **/
int _length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
/**
 * execute - functin to execute a command
 * @arg: the given command
 * @option: the options given to the command
 *
 * Return: 1 on success or -1 otherwise
 **/
int execute(char *arg, char **option)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("process failed");
		return (-1);
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		execve(arg, option, environ);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (1);
}
/**
 * free_memory_tokens - free the memory assigned for tokens
 * @tokens: the given tokens
 *
 * Return: Nothing
 **/
void free_memory_tokens(char **tokens)
{
	char **tmp = tokens;

	/**
	*if (tokens)
	*{
	*	while(*tokens)
	*	{
	*		printf("%p\n", *tokens);
	*		free(tokens++);
	*	}
	*	free(tmp);
	*}
	**/
	free(tmp);

}
