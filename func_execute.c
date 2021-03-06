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
	char *token = NULL;
	char **tokens = NULL;
	char *tmp = NULL;
	int i = 0;

	if (input == NULL)
		return (NULL);
	input = cleaner(input);
	if (input[0] != '\0')
	{
		tokens = malloc(sizeof(char *) * (length + 1));
		if (tokens == NULL)
			return (NULL);
		tmp = _strdup(input);
		token = strtok(tmp, separator);
		while (token)
		{
			tokens[i] = _strdup(token);
			token = strtok(NULL, separator);
			i++;
		}
		tokens[i] = '\0';
		if (token)
			free(token);
		if (tmp)
			free(tmp);
	}
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
		write(STDERR_FILENO, "process failed\n", 15);
		return (-1);
	}
	else if (pid == 0)
	{
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
 * @token: single dimensinal token
 *
 * Return: Nothing
 **/
void free_memory_tokens(char **tokens, char *token)
{
	char **tmp = tokens;

	if (tokens)
	{
		while (*tokens)
		{
			free(*tokens++);
		}
		free(tmp);
	}
	if (token)
		free(token);
}
/**
 * call_to_execute - ready for execution
 * @inpt: the given input
 * @arg: the argument values
 *
 * Return: 1 on sucess
 **/
int call_to_execute(char *inpt, char *arg)
{
	char **tokens = NULL, *cmd = NULL, *error1 = NULL;
	char *error2 = NULL, *error3 = NULL, *whichval = NULL;
	int (*f)(char **, char *, int count), len = _length(inpt), f_status = 0;

	inpt = var_replacement(inpt, f_status);
	tokens = tokenize(inpt, " \t", len);
	if (tokens == NULL)
		return (f_status);
	f = handle_built_in(tokens[0]);
	if (f == NULL)
	{
		cmd = _strdup(tokens[0]);
		whichval = _which(tokens[0]);
		if (whichval && access(whichval, X_OK) == 0)
			f_status = execute(whichval, tokens);
		else
		{
			if (cmd[0] == '/')
				error1 = _strcat(cmd, ": No such file or directory\n");
			else
				error1 = _strcat(cmd, ": command not found\n");
			error2 = _strcat(arg, ": ");
			error3 = _strcat(error2, error1);
			write(STDERR_FILENO, error3, _length(error3));
			f_status = -1;
			free(error1);
			free(error2);
			free(error3);
		}
		if (whichval && _strcmp(whichval, tokens[0]) != 0)
			free(whichval);
		if (cmd)
			free(cmd);
	} else
		f_status = f(tokens, arg, countTokens(tokens));
	free_memory_tokens(tokens, NULL);
	return (f_status);
}
