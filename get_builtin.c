#include "holberton.h"
/**
 * handle_built_in - function to handle built in
 * @command: the given argument
 *
 *
 * Return: the function pointer to handle the built in
 **/
int (*handle_built_in(char *command))(char **tokens, char *pname, int count)
{
	builtin_type blt[] = {
		{ "cd", handle_cd },
		{ "exit", customExit },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "alias", _alias },
		{ NULL, NULL }
	};
	int i = 0;

	while (blt[i].arg)
	{
		if (_strcmp(blt[i].arg, command) == 0)
			return (blt[i].f);
		i++;
	}
	return (NULL);
}
/**
 * handle_cd - function to handle cd
 * @tokens: the whole line
 * @prName: project name
 *
 * Return: 1 on success -1 otherwise
 **/
int handle_cd(char **tokens, char *prName, int __attribute__((__unused__)) count)
{
	char *abslt_path;
	int st = -1;

	if (countTokens(tokens) == 1 || _strcmp(tokens[1], "~") == 0)
	{
		abslt_path = _get_environ("HOME", environ);
		chdir(abslt_path);
		st = 1;
	}
	else if (_strcmp("..", tokens[1]) == 0)
	{
		chdir("..");
		st = 1;
	}
	else if (_strcmp("-", tokens[1]) == 0)
	{
		abslt_path = _get_environ("OLDPWD", environ);
		if (abslt_path != NULL)
		{
			chdir(abslt_path);
			st = 1;
		}
	}
	else if (_strcmp(".", tokens[1]) == 0)
	{
		abslt_path = _get_environ("PWD", environ);
		chdir(abslt_path);
		st = 1;
	}
	else
	{
		if (access(tokens[1], F_OK) == 0)
		{
			chdir(tokens[1]);
			st = 1;
		}
		else
		{
			printf("%s: cd failed", prName);
			st = -1;
		}
	}
	return (st);
}
/**
 * _get_environ - find the path of the given command
 * @n: the name to be searched
 * @env: the environment variable
 *
 * Return: the absolute path
 **/
char *_get_environ(char *n, char **env)
{
	int i, j, n_len = 0;
	char *str_env = NULL;
	char *path = NULL;

	n_len = _length(n);
	str_env = malloc(sizeof(char) * (n_len + 1));
	if (str_env == NULL)
	{
		free(str_env);
		return (NULL);
	}
	for (i = 0; env[i] != NULL; i++)
	{
		j = 0;
		while (j < n_len)
		{
			str_env[j] = env[i][j];
			j++;
		}
		str_env[j] = '\0';
		if (_strcmp(n, str_env) == 0)
		{
			free(path);
			path = _strdup(env[i]);
			break;
		}
	}
	if (path)
	{
		path = _mystrtok(path, "=");
		path = _mystrtok(NULL, "=");
	}
	free(str_env);
	return (path);
}
