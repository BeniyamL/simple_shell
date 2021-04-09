#include "holberton.h"
/**
 * var_replacement - funtion to replace a variable
 * @input: the given input
 *
 * Return: the replaced variable
 **/
char *var_replacement(char *input)
{
	char *rplc_str = NULL;
	int i;
	int totlen = 0, inptlen = 0, varlen = 0;
	char *new_input = NULL;
	char *tmp = NULL;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '$')
		{
			if (input[i + 1] == '?')
				;
			else if (input[i + 1] == '$')
			{
				rplc_str = int_to_str(getpid());
				break;
			}
			else
	 		{	
				rplc_str =_get_environ(cleaner(input + i + 1), environ);				break;			
			}
		}
	}
	if (rplc_str)
	{
		inptlen = i;
		varlen = _length(rplc_str);
		totlen = inptlen + varlen;
	}
	else
	{
		return (input);
	}
	new_input = malloc(sizeof(char) * (totlen + 1));
	new_input = replace_input(input, new_input, rplc_str, inptlen, varlen);
	tmp = _strdup(new_input);
	free(new_input);
	return (tmp);
}
/**
 * replace_input - function to replace a string
 * @input: the given string
 * @new_input: the replaces string
 * @len: the length of the new string
 *
 * Return: the new string
 **/
char *replace_input(char *input, char *new_input, char *rplc_str, int inptlen, int varlen)
{
	int i = 0, j = 0;

	while (i < inptlen)
	{
		if (input[i] != '$')
		{
			new_input[i] = input[i];
			i++;
		}
		else
			break;
	}
	while (j < varlen)
	{
		new_input[i] = rplc_str[j];
		j++;
		i++;
	}
	new_input[i] = '\0';
	return (new_input);
}
/**
 * int_to_str - convert int to string
 * @n: the given number
 *
 * Return: the equivalent string representation
 **/
char *int_to_str(int n)
{
	unsigned int num;
	int len = _intlen(n);
	char *buff;

	buff = malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (NULL);
	buff[len] = '\0';
	if (n < 0)
	{
		num = n * -1;
		buff[0] = '-';
	}
	else
	{
		num = n;
	}
	len--;
	while (num > 0)
	{
		buff[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (buff);
}
/**
 * _intlen - function to find length of a number
 * @n: the given number
 *
 * Return: the length of a number
 **/
int _intlen(int n)
{
	unsigned int num;
	int len = 1;

	if (n < 0)
	{
		len++;
		num = n * -1;
	}
	else
	{
		num = n;
	}
	while (num > 9)
	{
		len++;
		num = num / 10;
	}

	return (len);
}
