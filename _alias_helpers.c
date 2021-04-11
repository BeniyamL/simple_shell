#include "holberton.h"


/**
 * _alias - will create aliases for commands
 * @tokens: available tokens
 * @pname: program name
 * @count: number of tokens
 *
 * Return: return 0 on success and 1 of failure
 */
int _alias(char **tokens, char __attribute__((__unused__)) *pname, int count)
{
	int index = 1;

	if (count == 1)
	{
		printAllAliases();
		return (1);
	}
	while (tokens[index] != NULL)
	{
		getCommandType(tokens[index]);
		index++;
	}

	return (1);
}

/**
 * getCommandType - decide which command to execute
 * @command: alias command
 *
 * Return: int value of the command
 */
int getCommandType(char *command)
{
	char **aliasTokens = NULL;
	int count, found = 0, index = 0;

	aliasTokens = tokenize(command, "=", _length(command));
	count = countTokens(aliasTokens);
	if (count == 2)
	{
		if (_aliases == NULL)
		{
			addAlias(aliasTokens[0], aliasTokens[1]);
			return (1);
		}
		index = 0;
		while (_aliases[index] != NULL)
		{
			if (_strcmp(_aliases[index]->key, aliasTokens[0]) == 0)
			{
				found = 1;
				break;
			}
			index++;
		}
		if (found == 0)
		{
			addAlias(aliasTokens[0], aliasTokens[1]);
		}
		else
			updateAlias(aliasTokens[0], aliasTokens[1]);
	} else if (count == 1)
	{
		printAlias(aliasTokens[0]);
	}

	return (1);
}
