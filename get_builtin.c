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
 * @cnt: the number of tokesn
 *
 * Return: 1 on success -1 otherwise
 **/
int handle_cd(char **tokens, char *prName, int __attribute__((__unused__)) cnt)
{
	char *abslt_path;
	int st = -1;
	char pwd[PATH_MAX];
	char *pwd_pr;

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
		getcwd(pwd, sizeof(pwd));
		pwd_pr = _strdup(pwd);
		chdir(pwd_pr);
		st = 1;
	}
	else
	{
		st = cd_to_path(tokens, prName);
	}
	return (st);
}
/**
 * cd_to_path - function to navigate to a given path
 * @tokens: the tokens
 * @prName: program name
 *
 * Return: the status of the execution
 **/
int cd_to_path(char **tokens, char *prName)
{
	int st = -1;
	char *err;

	if (access(tokens[1], F_OK) == 0)
	{
		chdir(tokens[1]);
		st = 1;
	}
	else
	{
		err = prName;
		_strcat(err, ": cd failed");
		write(STDERR_FILENO, err, _length(err));
		st = -1;
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
			path = _strdup(env[i]);
			break;
		}
	}
	if (path)
	{
		path = strtok(path, "=");
		path = strtok(NULL, "=");
	}
	free(str_env);
	return (path);
}
/**
 * setcustomenv - to sent the environment variable
 * @name: the name of the variable
 * @value: the value of the variable
 *
 * Return: nothing
 **/
void setcustomenv(char *name, char *value)
{
	int i = 0;
	char *key;
	char *newval;
	int len;

	len = _length(name) + _length(value) + 2;
	newval = malloc(sizeof(char) * len);
	while (environ[i] != NULL)
	{
		key = getKey(environ[i]);
		if (key != NULL && _strcmp(key, name) == 0)
		{
			_strcopy(newval, name);
			_strcat(newval, "=");
			_strcat(newval, value);
			_strcat(newval, "\0");
			environ[i] = newval;
		}
		i++;
	}
	free(newval);
}
