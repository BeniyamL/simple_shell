#include "holberton.h"
/**
 * _mystrtok - custom function to split a string
 * @str: the given string
 * @del: the delimiter
 *
 * Return: the splited string
 **/
char *_mystrtok(char *str, char *del)
{
	static char *line;
	int strlength, dellength = _length(del), i, index = 0, flag = 0;

	if (str != NULL)
	{
		strlength = _length(str);
		line = malloc(sizeof(char) * (strlength + 1));
		_strcopy(line, str);
	}
	else if (line == NULL)
		return (NULL);
	else
		str = _strdup(line);
	while (*line)
	{
		for (i = 0; i < dellength; i++)
		{
			if (line[i] == del[i])
			{
				if (index == 0)
				{
					flag = 1;
					str++;
				}
				else
				{
					line++;
					str[index] = '\0';
					return (str);
				}
			}
		}
		if (flag == 0)
			index++;
		line++;
		flag = 0;
	}
	line = NULL;
	str[index] = '\0';
	return (str);
}
/**
 * _strcopy - copy string from source to dest
 * @src: the source of the string
 * @dest: the destination string
 *
 * Return: the copied string
 **/
char *_strcopy(char *dest, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - function to duplicate a string
 * @str: the given string
 *
 * Return: the duplicated string
 **/
char *_strdup(char *str)
{
	char *dup;
	int i = 0;
	int strlength = 0;

	if (str == NULL)
		return (NULL);
	strlength = _length(str);
	dup = malloc(sizeof(char) * (strlength + 1));
	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/**
 * _mystrtok2 - function to split a string
 * @str: the given string
 * @del: the delimeter
 *
 * Return: the splited string
 **/
char *_mystrtok2(char *str, char *del)
{
	static char *line;
	int strlength, dellength = _length(del), i, index = 0, flag = 0;

	if (str != NULL)
	{
		strlength = _length(str);
		line = malloc(sizeof(char) * (strlength + 1));
		_strcopy(line, str);
	}
	else if (line == NULL)
		return (NULL);
	else
		str = _strdup(line);
	while (*line)
	{
		for (i = 0; i < dellength; i++)
		{
			if (line[i] == del[i])
			{
				if (index == 0)
				{
					flag = 1;
					str++;
				}
				else
				{
					line++;
					str[index] = '\0';
					return (str);
				}
			}
		}
		if (flag == 0)
			index++;
		line++;
		flag = 0;
	}
	line = NULL;
	str[index] = '\0';
	return (str);
}

