#include "holberton.h"
/**
 * _strcat - function to concate strings
 * @dest: the destinatin string
 * @src: the source string
 *
 * Return: the concatednated string
 **/
char *_strcat(char *dest, char *src)
{
	char *tmpdest;
	int len, index = 0, srcindex = 0;

	len = _length(dest) + _length(src) + 1;
	tmpdest = malloc(sizeof(char) * len);
	if (tmpdest == NULL)
	{
		free(tmpdest);
		return (NULL);
	}

	while (dest[index] != '\0')
	{
		tmpdest[index] = dest[index];
		index++;
	}
	while (src[srcindex] != '\0')
	{
		tmpdest[index] = src[srcindex];
		index++;
		srcindex++;
	}

	tmpdest[index] = '\0';
	return (tmpdest);
}
/**
 * _strncmp - function that compares n characters
 * @s1: the first string
 * @s2: the second string
 * @n: the number of characters to compare
 *
 * Return: 0 if the same, > 0 if s1 >s2 and < 0 if s1 < s2
 **/
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n ; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-1);
}
/**
 * _strcmp - compares to strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if equal lest than 0 if s2 is greater and
 * greater 0 if s1 is greater
 */
int _strcmp(char *s1, char *s2)
{
	int l = 0;

	while (1)
	{
		if (s1[l] == '\0' && s2[l] == '\0')
			return (0);
		else if (s1[l] == s2[l])
		{
			l++;
			continue;
		}
		else
			return (s1[l] - s2[l]);
		l++;
	}
}
/**
 * _length - function that finds the length of a string
 * @str: the given string
 *
 * Return: the length of a string
 **/
int _length(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
