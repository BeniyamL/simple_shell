#include "holberton.h"

/**
 * customExit - exit the shell
 * @tokens: command entered
 * @prName: program name
 * @count: tokens count
 *
 * Return: nothing
 */
int customExit(char **tokens, char *prName, int __attribute__((__unused__)) count)
{
	int isNumeric = 0, value;
	char *msg;

	if (count == 1)
	{
		//printf("exit\n");
		write(STDERR_FILENO,"exit\n", 5);
		free_memory_tokens(tokens, NULL);
		exit(0);
		return (1);
	}
	isNumeric = checkNumber(tokens[1]);
	if (isNumeric == 0)
	{
		msg = prName;
		_strcat(msg, ":exit: ");
		_strcat(msg, tokens[1]);
		_strcat(msg, ": numeric argument required\n");
		write(STDERR_FILENO, msg, _length(msg));
		//printf("%s: exit: %s: numeric argument required\n", prName, tokens[1]);
		free_memory_tokens(tokens, NULL);
		exit(0);
		return (1);
	}
	value = getNumericValue(tokens[1], _length(tokens[1]));
	if (count > 2)
	{
		msg = prName;
		_strcat(msg, ": exit: too many arguments\n");
		write(STDERR_FILENO,msg, _length(msg));
		//printf("%s: exit: too many arguments\n", prName);
		return (-1);
		
	}
	write(STDERR_FILENO,"exit\n", 5);
	//printf("exit\n");
	free_memory_tokens(tokens, NULL);
	exit(value);
	return (1);
}

/**
 * checkNumber - check if a string is a number
 * @token: a string
 *
 * Return: 0 or 1
 */
int checkNumber(char *token)
{
	int count = 0;

	while (token[count] != '\0')
	{
		if (token[count] < '0' || token[count] > '9')
			return (0);
		count++;
	}
	return (1);
}

/**
 * getNumericValue - get numeric value of a string
 * @token: a string of numbers
 * @len: current number to process
 *
 * Return: numeric value of a string
 */
int getNumericValue(char *token, int len)
{
	int sum = 0, value, num;

	while (len > 0)
	{
		num = token[len - 1] - '0';
		value = num * _pow(10, len - 1);
		sum += value;
		len--;
	}

	return (sum);
}

/**
 * _pow - calculate power of a number
 * @base: the base of power func
 * @exp: exponent of the power func
 *
 * Return: calculated power value
 */
int _pow(int base, int exp)
{
	int val = base;

	if (exp == 0)
		return (1);

	if (exp == 1)
		return (base);
	while (exp > 1)
	{
		val *= base;
		exp--;
	}
	return (val);
}

/**
 * countTokens - count number of tokens
 * @tokens: tokens returned from tokenizer
 *
 * Return: number of elements in token
 */
int countTokens(char **tokens)
{
	int count = 0;

	while (tokens[count] != NULL)
	{
		count++;
	}
	return (count);
}
