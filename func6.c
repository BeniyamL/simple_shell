#include "holberton.h"

/**
 * _signal - will handle signal sent to the program
 *
 * Return: nothing
 */
void _signal(void)
{
	struct sigaction sa = {0};

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
 * @pname: program namels
 * @count: tokens count
 *
 * Return: key on success NULL on failure
 */
int _setenv(char **tokens, char __attribute__((__unused__)) *pname, int count)
{
	int index = 0;
	char *key, *newVar;

	if (count < 3)
		return (-1);
	newVar = createNewEnvStr(tokens);
	while (environ[index] != NULL)
	{
		key = getKey(environ[index]);
		if (key != NULL && _strcmp(key, tokens[1]) == 0)
		{
			environ[index] = newVar;
			return (1);
		}
		index++;
	}

	environ[index] = newVar;
	environ[index + 1] = NULL;
	return (1);
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

/**
 * handleSubaliases - will handle eliases in logical operator commands
 * @input: command to execute
 * @arg: argument prname
 *
 * Return: int
 */
int handleSubaliases(char *input, char *arg)
{
	int characterlen = 0, commandLen, commandIndex;
	char **commands = NULL, **tokens = NULL;
	int f_status = 0;

	characterlen = _length(input);
	if (characterlen > 0 && input[0] != '\n')
	{
		commands = tokenize(input, ";", characterlen);
		commandIndex = 0;
		while (commands[commandIndex] != NULL)
		{
			commandLen = _length(commands[commandIndex]);
			tokens = tokenize(commands[commandIndex], " \t", commandLen);
			f_status = handle_args(commands[commandIndex], tokens, arg);
			if (f_status == -1)
			{
				f_status = call_to_execute(input, arg);
			}
		}
	}
	return (f_status);
}

