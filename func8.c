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
 * @pname: program name
 * @c: the number of tokens
 *
 * Return: key on success NULL of failure
 */
int _unsetenv(char **tokens, char __attribute__((__unused__)) *pname, int c)
{
	int index = 0, newIndex = 0, removed = 0;
	char *key;

	if (c != 2)
		return (1);

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
