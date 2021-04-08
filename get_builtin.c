#include "holberton.h"
/**
 * handle_built_in - function to handle built in
 * @argv: the given argument
 *
 * Return: the function pointer to handle the built in
 **/
int (*handle_built_in(char *command))(char **tokens)
{
	builtin_type blt[] = {
 		{ "cd", handle_cd },
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
 * @cmd: the given command
 * @tokens: the whole line
 *
 * Return: 1 on success -1 otherwise
 **/
int handle_cd(char **tokens)
{
	char *abslt_path;

	if (countTokens(tokens) == 1 || _strcmp(tokens[1], "~") == 0)
	{
		abslt_path = _get_environ("HOME", environ);
		return (chdir(abslt_path));
	}
	else if (_strcmp("..", tokens[1]) == 0)
        {
		return (chdir(".."));
        }
	else if (_strcmp("-", tokens[1]) == 0)
        {
		abslt_path = _get_environ("OLDPWD", environ);
		if(abslt_path != NULL)
		{
			return (chdir(abslt_path));
		}
        }
	else if (_strcmp(".", tokens[1]) == 0)
        {
		abslt_path = _get_environ("PWD", environ);
		return (chdir(abslt_path));
        }
	else
        {
		if (access(tokens[1], F_OK) == 0)
		{
                	return (chdir(tokens[1]));
		}
		else
		{
			perror("cd failed");
			return (-1);
		}
        }
	return (-1);
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
