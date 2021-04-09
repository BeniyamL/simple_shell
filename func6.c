#include "holberton.h"

/**
 * _signal - will handle signal sent to the program
 *
 * Return: nothing
 */
void _signal(void)
{
	struct sigaction sa;

	sa.sa_handler = &signalHandler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}

/**
 * signalHandler - will handle program signals
 * @sigInt: signal value
 *
 * Return: nothing
 */
void signalHandler(int __attribute__((__unused__)) sigInt)
{
}

/**
 * _setenv - set env value
 * @tokens: tokens values
 * @count: tokens count
 *
 * Return: key on success NULL on failure
 */
char *_setenv(char **tokens, int count)
{
	int index = 0;
	char *key, *newVar;

	if (count < 3)
		return (NULL);
	newVar = createNewEnvStr(tokens);
	while (environ[index] != NULL)
	{
		key = getKey(environ[index]);
		if (key != NULL && _strcmp(key, tokens[1]) == 0)
		{
			environ[index] = newVar;
			return (newVar);
		}
		index++;
	}

	environ[index] = newVar;
	environ[index + 1] = NULL;
	return (NULL);
}

/**
 * getKey - get key of env value
 * @var: the global variable
 *
 * Return: the key of the variable
 */
char *getKey(char *var)
{
	int keyLen = 0, index = 0;
	char *key;

	while (var[keyLen] != '=')
		keyLen++;

	key = malloc(keyLen * sizeof(char));
	if (key == NULL)
		return (NULL);

	for (index = 0; index < keyLen; index++)
		key[index] = var[index];

	return (key);
}
