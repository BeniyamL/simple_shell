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
	size_t psIdx = 0, pIdx = 0, pathLength = 100;
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);
	paths = getenv("PATH");
	if (paths == NULL)
		return (NULL);
	path = malloc(pathLength);
	if (path == NULL)
	{
		free(path);
		return (NULL);
	}
	while (1)
	{
		path = reallocateMemory(&path, &pathLength, pIdx);
		if (path == NULL)
			return (NULL);
		if (paths[psIdx] == ':' || paths[psIdx] == '\0')
		{
			path[pIdx] = '/';
			path = appendCommand(path, command, ++pIdx, &pathLength);
			if (path == NULL)
				return (NULL);
			if (stat(path, &st) == 0)
				return (path);
			pIdx = 0;
			if (paths[++psIdx] == '\0')
			{
				free(path);
				return (NULL);
			}
		} else
		{
			path[pIdx++] = paths[psIdx++];
		}
	}
}

/**
 * reallocateMemory - realocate path memeory
 * @path: reallocate path
 * @pathLength: new length
 * @pIdx: comparison length
 *
 * Return: new reallocated path
 */
char *reallocateMemory(char **path, size_t *pathLength, size_t pIdx)
{
	if (pIdx >= *pathLength)
	{
		*pathLength += *pathLength;
		*path = realloc(*path, *pathLength);
		if (path == NULL)
		{
			free(*path);
			return (NULL);
		}
	}
	return (*path);
}

/**
 * appendCommand - append a command to path
 * @path: path to append a command to
 * @pIdx: current path index
 * @command: a command to append
 * @pathLength: current path length
 *
 * Return: path with command appended
 */
char *appendCommand(char *path, char *command, size_t pIdx, size_t *pathLength)
{
	int cmIdx = 0;

	while (command[cmIdx] != '\0')
	{
		if ((pIdx + cmIdx) >= *pathLength)
		{
			*pathLength += *pathLength;
			path = realloc(path, *pathLength);
			if (path == NULL)
			{
				free(path);
				return (NULL);
			}
		}
		path[pIdx + cmIdx] = command[cmIdx];
		cmIdx++;
	}
	path[pIdx + cmIdx] = '\0';
	return (path);
}

/**
 * _getline - custom get line function
 * @prName: program name
 *
 * Return: one line string
 */
char *_getline(char *prName)
{
	char *line = NULL, *msg = NULL;
	size_t bufsize = 1024;

	msg = _strcat(prName, "$ ");
	if (isatty(0) == 1)
		write(STDOUT_FILENO, msg, _length(msg));

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		free(msg);
		exit(0);
	}
	free(msg);
	return (line);
}

