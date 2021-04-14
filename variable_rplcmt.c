#include "holberton.h"
/**
 * var_replacement - funtion to replace a variable
 * @in: the given input
 *
 * Return: the replaced variable
 **/
char *var_replacement(char *in, int f_status)
{
	int totlen = 0, i;
	char *new_input = NULL, *tmp = NULL, *rplc_str = NULL;

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
			{
				rplc_str = int_to_str(f_status);
				break;
			}
			else if (in[i + 1] == '$')
			{
				rplc_str = int_to_str(getpid());
				break;
			}
			else if (in[i + 1] == '\n' || in[i + 1] == ' ' || in[i + 1] == '\0')
			{
				rplc_str = NULL;
				break;
			}
			else
			{
				rplc_str = _get_environ(cleaner(in + i + 1), environ);
				if (rplc_str == NULL)
					rplc_str = "\n";
				break;
			}
		}
	}
	if (rplc_str)
		totlen = i + _length(rplc_str);
	else
		return (in);
	new_input = malloc(sizeof(char) * (totlen + 1));
	new_input = rep_input(in, new_input, rplc_str, i, _length(rplc_str));
	tmp = _strdup(new_input);
	free(new_input);
	return (tmp);
}
/**
 * rep_input - function to replace a string
 * @ipt: the given string
 * @nw_ipt: the replaces string
 * @rplc_str: the length of the new string
 * @iptlen: input len
 * @vlen: variable len
 *
 * Return: the new string
 **/
char *rep_input(char *ipt, char *nw_ipt, char *rplc_str, int iptlen, int vlen)
{
	int i = 0, j = 0;

	while (i < iptlen)
	{
		if (ipt[i] != '$')
		{
			nw_ipt[i] = ipt[i];
			i++;
		}
		else
			break;
	}
	while (j < vlen)
	{
		nw_ipt[i] = rplc_str[j];
		j++;
		i++;
	}
	nw_ipt[i] = '\0';
	return (nw_ipt);
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
