#include "holberton.h"

/**
 * createNewEnvStr - will create a new env variable
 * @tokens: info for the new variable
 *
 * Return: a concated string
 */
char *createNewEnvStr(char **tokens)
{
	int keyLen, valLen, len, newVarIndex = 0;
	char *newVar;

	keyLen = _length(tokens[1]);
	valLen = _length(tokens[2]);
	len = keyLen + valLen + 1;
	newVar = malloc(len * sizeof(char));
	if (newVar == NULL)
		return (NULL);
	while (newVarIndex < len)
	{
		if (newVarIndex < keyLen)
			newVar[newVarIndex] = tokens[1][newVarIndex];
		else if (newVarIndex == keyLen)
			newVar[newVarIndex] = '=';
		else
			newVar[newVarIndex] = tokens[2][newVarIndex - keyLen - 1];
		newVarIndex++;
	}

	return (newVar);
}

/**
 * _unsetenv - will remove a variable from environ
 * @tokens: a variable to remove
 * @count: the number of tokens
 *
 * Return: key on success NULL of failure
 */
char *_unsetenv(char **tokens, int count)
{
	int index = 0, newIndex = 0, removed = 0;
	char *key;

	if (count != 2)
		return (NULL);

	while (environ[index] != NULL)
	{
		key = getKey(environ[index]);
		if (key != NULL && _strcmp(key, tokens[1]) == 0)
		{
			index++;
			removed = 1;
			continue;
		}
		environ[newIndex] = environ[index];
		newIndex++;
		index++;
	}
	if (removed == 0)
		perror("Variable not found");
	else
		environ[newIndex] = NULL;
	return (key);
}

/**
 * _alias - will create aliases for commands
 * @tokens: available tokens
 * @count: number of tokens
 *
 * Return: return 0 on success and 1 of failure
 */
int _alias(char **tokens, int count)
{
	int index = 1;

	if (count == 1)
	{
		printAllAliases();
		return (0);
	}
	while (tokens[index] != NULL)
	{
		getCommandType(tokens[index]);
		index++;
	}

	return (0);
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
			return (0);
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

/**
 * _strContains - check if a string container a character
 * @str: a string
 * @c: a character
 *
 * Return: 0 if it contains and other if it doesn't
 */
int _strContains(char *str, char c)
{
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (0);
		index++;
	}
	return (1);
}
