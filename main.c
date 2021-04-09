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
				if (_strcmp(tokens[0], "exit") == 0)
					customExit(tokens, countTokens(tokens), argv[0]);
				else if (_strcmp(tokens[0], "setenv") == 0)
					_setenv(tokens, countTokens(tokens));
				else if (_strcmp(tokens[0], "unsetenv") == 0)
					_unsetenv(tokens, countTokens(tokens));
				else if (_strcmp(tokens[0], "alias") == 0)
					_alias(tokens, countTokens(tokens));
				else if (countTokens(tokens) >= 1 && checkCommandAlias(tokens[0]) != NULL)
				{
					alias = 1;
					input = concatTokens(tokens, checkCommandAlias(tokens[0]));
					break;
				}
				else
				{
					tokens[0] = _which(tokens[0]);
					if (tokens[0] && access(tokens[0], X_OK) == 0)
						status = execute(tokens[0], tokens);
					else
						perror("./hsh");
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
			return _aliases[index]->command;
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
