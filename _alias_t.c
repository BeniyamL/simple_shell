#include "holberton.h"

/**
 * addAlias - add alias to the list of aliases
 * @key: the alias
 * @command: a command the alias referse to
 *
 * Return: the key of the alias
 */
alias_t *addAlias(char *key, char *command)
{
	alias_t *newAlias;
	int len;

	newAlias = malloc(sizeof(alias_t));
	if (newAlias == NULL)
		return (NULL);

	newAlias->key = key;
	newAlias->command = command;

	if (_aliases == NULL)
	{
		_aliases = malloc(sizeof(newAlias) * 2);
		if (_aliases == NULL)
			return (NULL);
		_aliases[0] = newAlias;
		_aliases[1] = NULL;
	} else
	{
		len = countAliases();
		_aliases = realloc(_aliases, sizeof(newAlias) * (len + 1));
		if (_aliases == NULL)
			return (NULL);
		_aliases[len] = newAlias;
		_aliases[len + 1] = NULL;
	}
	return (newAlias);
}

/**
 * countAliases - get number of aliases
 *
 * Return: number of aliases
 */
int countAliases(void)
{
	int index = 0;

	if (_aliases == NULL)
		return (0);
	while (_aliases[index] != NULL)
		index++;
	return (index);
}
/**
 * updateAlias - update an existing alias
 * @key: key of alias
 * @command: command of alias
 *
 * Return: the updated alias
 */
alias_t *updateAlias(char *key, char *command)
{
	int index = 0;

	while (_aliases[index] != NULL)
	{
		if (_strcmp(_aliases[index]->key, key) == 0)
		{
			_aliases[index]->command = command;
			return (_aliases[index]);
		}
		index++;
	}

	return (NULL);
}

/**
 * printAlias - print one alias
 * @key: alias key
 *
 * Return: nothing
 */
void printAlias(char *key)
{
	int index = 0;

	if (_aliases != NULL)
	{
		while (_aliases[index] != NULL)
		{
			if (_strcmp(_aliases[index]->key, key) == 0)
				printf("%s='%s'\n", _aliases[index]->key, _aliases[index]->command);
			index++;
		}
	}
}

/**
 * printAllAliases - print all aliases
 *
 * Return: nothing
 */
void printAllAliases(void)
{
	int index = 0;

	if (_aliases != NULL)
	{
		while (_aliases[index] != NULL)
		{
			printf("%s='%s'\n", _aliases[index]->key, _aliases[index]->command);
			index++;
		}
	}
}
