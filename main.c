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
	char **tokens = NULL, **commands = NULL;
	int characterlen = 0, commandLen = 0, commandIndex = 0, status = 1, alias = 0;

	_signal();
	signal(SIGINT, SIG_IGN);
	do {
		if (alias == 0)
			input = _getline(argv[0]);
		else
			alias = 0;
		characterlen = _length(input);
		if (characterlen > 0 && input[0] != '\n')
		{
			commands = tokenize(input, ";", characterlen);
			commandIndex = 0;
			while (commands[commandIndex] != NULL)
			{
				commandLen = _length(commands[commandIndex]);
				tokens = tokenize(commands[commandIndex], " \t", commandLen);
				if (handle_args(commands[commandIndex], tokens, argv[0]) == -1)
				{
					if (countTokens(tokens) >= 1 && checkCommandAlias(tokens[0]) != NULL)
					{
						alias = 1;
						input = concatTokens(tokens, checkCommandAlias(tokens[0]));
						break;
					}
					status = call_to_execute(commands[commandIndex], argv[0]);
				}
				commandIndex++;
			}
		}
		if (alias == 0)
			free(input);
	} while (status);
	return (0);
}

/**
 * checkCommandAlias - will check if command exists in aliases
 * @key: command to check
 *
 * Return: the value if exists NULL otherwise
 */
char *checkCommandAlias(char *key)
{
	int index = 0;

	if (_aliases == NULL)
		return (NULL);

	while (_aliases[index] != NULL)
	{
		if (_strcmp(_aliases[index]->key, key) == 0)
			return (_aliases[index]->command);
		index++;
	}

	return (NULL);
}

/**
 * concatTokens - will concat tokens
 * @tokens: tokens
 * @newValue: value to replace tokens[0]
 *
 * Return: the concated text
 */
char *concatTokens(char **tokens, char *newValue)
{
	int index = 0, indexTemp = 0, tokenIndex = 1;
	char *newStr;

	index += _length(newValue) + 1;
	while (tokens[tokenIndex] != NULL)
	{
		index += _length(tokens[tokenIndex]) + 1;
		tokenIndex++;
	}
	newStr = malloc(sizeof(char) * index);
	index = 0;
	indexTemp = 0;
	tokenIndex = 1;
	while (newValue[indexTemp] != '\0')
	{
		newStr[index] = newValue[indexTemp];
		index++;
		indexTemp++;
	}
	newStr[index] = ' ';
	index++;
	while (tokens[tokenIndex] != NULL)
	{
		indexTemp = 0;
		while (tokens[tokenIndex][indexTemp] != '\0')
		{
			newStr[index] = tokens[tokenIndex][indexTemp];
			index++;
			indexTemp++;
		}
		newStr[index] = ' ';
		index++;
		tokenIndex++;
	}
	newStr[index] = '\0';
	return (newStr);
}
/**
 * handle_args - function to handle logical operators
 * @str: the input string
 * @tokens: the input tokens
 * @argv: the argument values
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
		if (_strncmp(tokens[i], "&&", 2) == 0)
		{
			tmp = _strdup(str);
			arg = strtok(str, "&&");
			while (arg)
			{
				status = call_to_execute(arg, argv);
				if (status != -1)
					arg = strtok(NULL, "&&");
				else
					arg = NULL;
			}
			return (1);
		}
		else if (_strncmp(tokens[i], "||", 2) == 0)
		{
			tmp = _strdup(str);
			arg = strtok(tmp, "||");
			while (arg)
			{
				status = call_to_execute(arg, argv);
				if (status != -1)
					arg = NULL;
				else
					arg = strtok(NULL, "||");
			}
			return (1);
		}
	}
	return (-1);
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
	char **tokens = NULL;
	int (*f)(char **, char *, int count);
	int status = -1;
	int len = 0;
	char *cmd = NULL;

	inpt = var_replacement(inpt);
	len = _length(inpt);
	tokens = tokenize(inpt, " \t", len);
	f = handle_built_in(tokens[0]);
	if (f == NULL)
	{
		if (countTokens(tokens) >= 1 && checkCommandAlias(tokens[0]) != NULL)
		{
			inpt = concatTokens(tokens, checkCommandAlias(tokens[0]));
			status = handleSubaliases(inpt, arg);
			return (status);
		}
		cmd = _strdup(tokens[0]);
		tokens[0] = _which(tokens[0]);
		if (tokens[0] && access(tokens[0], X_OK) == 0)
		{
			status = execute(tokens[0], tokens);
			free_memory_tokens(tokens, NULL);
		}

		else
		{
			perror(cmd);
			perror(": command not found");
			free_memory_tokens(tokens, NULL);
			status = -1;
		}
	}
	else
	{
		status = f(tokens, arg, countTokens(tokens));
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
