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
	int characterlen = 0;
	int f_status = 0;

	_signal();
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		input = _getline(argv[0]);
		characterlen = _length(input);
		if (characterlen > 0 && input[0] != '\n')
		{
			tokens = tokenize(input, " \t", characterlen);
			f_status = handle_args(input, tokens, argv[0]);
			if (f_status == -1)
			{
				f_status = call_to_execute(input, argv[0]);
			}
		}
		free(input);
	}
	return (f_status);
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
	char *arg = str, *tmp = NULL;
	int i, f_status = 0;

	for (i = 0; tokens[i]; i++)
	{
		if (_strncmp(tokens[i], "&&", 2) == 0)
		{
			tmp = _strdup(str);
			arg = _mystrtok2(tmp, "&&");
			while (arg)
			{
				f_status = call_to_execute(arg, argv);
				if (f_status != -1)
					arg = _mystrtok2(NULL, "&&");
				else
					arg = NULL;
			}
			return (1);
		}
		else if (_strncmp(tokens[i], "||", 2) == 0)
		{
			tmp = _strdup(str);
			arg = _mystrtok2(tmp, "||");
			while (arg)
			{
				f_status = call_to_execute(arg, argv);
				if (f_status != -1)
					arg = NULL;
				else
					arg = _mystrtok2(NULL, "||");
			}
			return (1);
		}
		else if (_strncmp(tokens[i], ";", 1) == 0)
		{
			f_status = handle_semicolon(str, argv);
			return (1);
		}
	}
	return (-1);
}
/**
 * handle_semicolon - function to handle semi colon separator
 * @str: the given string
 * @argv: the argument
 *
 * Return: 1
 **/
int handle_semicolon(char *str, char *argv)
{
	char *tmp = NULL, *arg = NULL;
	int f_status = 0;

	tmp = _strdup(str);
	arg = _mystrtok2(tmp, ";");
	while (arg)
	{
		f_status = call_to_execute(arg, argv);
		arg = _mystrtok2(NULL, ";");
	}
	return (f_status);
}
