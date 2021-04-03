#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "holberton.h"

/**
 * _which - find command in PATH
 * @command: a command string
 *
 * Return: the directory of a command
 */
char *_which(char *command)
{
	char *paths, *path;
	size_t pathsIndex = 0, pathIndex = 0, commandIndex = 0, pathLength = 100;
	struct stat st;

	paths = getenv("PATH");
	path = malloc(pathLength);
	if (path == NULL)
	{
		free(path);
		return (NULL);
	}
	while (1)
	{
		if (pathIndex >= pathLength)
		{
			pathLength += pathLength;
			path = realloc(path, pathLength);
			if (path == NULL)
			{
				free(path);
				return (NULL);
			}
		}
		if (paths[pathsIndex] == ':' || paths[pathsIndex] == '\0')
		{
			path[pathIndex] = '/';
			pathIndex++;
			commandIndex = 0;
			while (command[commandIndex] != '\0')
			{
				if ((pathIndex + commandIndex) >= pathLength)
				{
					pathLength += pathLength;
					path = realloc(path, pathLength);
					if (path == NULL)
					{
						free(path);
						return (NULL);
					}
				}
				path[pathIndex + commandIndex] = command[commandIndex];
				commandIndex++;
			}
			path[pathIndex + commandIndex] = '\0';
			if (stat(path, &st) == 0)
			{
				return (path);
			}
			pathIndex = 0;
			pathsIndex++;
			if (paths[pathsIndex] == '\0')
				break;
			continue;
		} else
		{
			path[pathIndex] = paths[pathsIndex];
			pathsIndex++;
			pathIndex++;
		}
	}

	return (NULL);
}

/**
 * _getline - custom get line function
 *
 * Return: one line string
 */
char *_getline(char *prName)
{
	char *line;
	int c;
	size_t i = 0, strLen = 1024;

	line = malloc(sizeof(char) * strLen);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	printf("%s$ ", prName);
	c = getchar();

	while (c != '\n')
	{
		if (c == EOF)
		{
			printf("\n");
			exit(100);
		}
		if (i > strLen - 1)
		{
			strLen += 1024;
			line = realloc(line, strLen);
			if (line == NULL)
			{
				free(line);
				return (NULL);
			}
		}
		line[i] = c;
		i++;
		c = getchar();
	}
	line[i] = '\0';
	return (line);
}
